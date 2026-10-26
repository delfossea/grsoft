import subprocess
import os

def run_test(test_name):
    bas_file = f"tests/{test_name}.bas"
    exp_file = f"tests/{test_name}.exp"
    
    print(f"Running {test_name}...", end=" ")
    
    try:
        # Run the 'soft' program with the .bas file as input
        with open(bas_file, 'r') as f_in:
            process = subprocess.run(['./soft'], stdin=f_in, capture_output=True, text=True, timeout=5)
        
        # Check if soft.c was created
        if not os.path.exists('soft.c'):
            print("FAIL (soft.c not created)")
            return False
            
        with open('soft.c', 'r') as f_out:
            actual = f_out.read()
            
        with open(exp_file, 'r') as f_exp:
            expected = f_exp.read()
            
        if actual.strip() == expected.strip():
            print("PASS")
            return True
        else:
            print("FAIL (mismatch)")
            with open('diff_output.txt', 'w') as f_diff:
                f_diff.write("EXPECTED:\n" + expected + "\n\nACTUAL:\n" + actual)
            return False
            
    except Exception as e:
        print(f"ERROR ({e})")
        return False

def main():
    # Compile first
    print("Compiling soft...")
    compile_res = subprocess.run(['make'], capture_output=True)
    if compile_res.returncode != 0:
        print("Compilation failed!")
        print(compile_res.stderr.decode())
        return

    tests = ['test_let', 'test_print', 'test_goto', 'test_for', 'test_if', 'test_dim', 'test_gosub']
    passed = 0
    for t in tests:
        if run_test(t):
            passed += 1
            
    print(f"\nResults: {passed}/{len(tests)} tests passed.")

if __name__ == "__main__":
    main()
