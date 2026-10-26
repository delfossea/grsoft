import subprocess
import os

def run_test(test_name):
    im_file = f"tests/im/{test_name}.im"
    out_file = f"tests/im/{test_name}.out"
    
    print(f"Running {test_name}...", end=" ")
    
    try:
        with open(im_file, 'r') as f_in:
            # We need to send a carriage return after each line to simulate the 'CR' token
            # In your soft.y, the pgm rule expects a CR
            input_text = f_in.read()
            if not input_text.endswith('\n'):
                input_text += '\n'
            
            # We add 'SYSTEM' at the end to make the program exit
            input_text += 'SYSTEM\n'
            
            process = subprocess.run(['./soft'], input=input_text, capture_output=True, text=True, timeout=5)
        
        actual = process.stdout
        # Remove prompts ']' for comparison
        actual_cleaned = actual.replace(']', '').strip()

        with open(out_file, 'r') as f_exp:
            expected_lines = [line.strip() for line in f_exp.readlines() if line.strip()]

        all_found = True
        for exp_line in expected_lines:
            if exp_line not in actual_cleaned:
                all_found = False
                break

        if all_found:
            print("PASS")
            return True
        else:
            print("FAIL (mismatch)")
            print(f"  Expected lines to find: {expected_lines}")
            print(f"  Actual output (cleaned):\n{actual_cleaned}")
            return False
            
    except Exception as e:
        print(f"ERROR ({e})")
        return False

def main():
    print("Compiling soft...")
    subprocess.run(['make'], capture_output=True)

    tests = ['test_let', 'test_print', 'test_for', 'test_if']
    passed = 0
    for t in tests:
        if run_test(t):
            passed += 1
            
    print(f"\nResults: {passed}/{len(tests)} tests passed.")

if __name__ == "__main__":
    main()
