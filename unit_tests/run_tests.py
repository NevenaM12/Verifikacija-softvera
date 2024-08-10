import subprocess
import os

def compile_test(test_file):
    output_executable = test_file.replace('.cpp', '')
    compile_command = [
        "g++",
        f"../2048/src/Game.cpp",
        f"../2048/src/KeyPushManager.cpp",
        f"../2048/src/Kbhit.cpp",
        f"../2048/src/Utils.cpp",
        f"{test_file}",
        "-o",
        output_executable,
        "-I", "../2024/app",
        "-lstdc++"
    ]

    result = subprocess.run(compile_command, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Compilation failed for {test_file}:\n{result.stderr}")
    else:
        print(f"Compilation succeeded for {test_file}.")
    return output_executable if result.returncode == 0 else None

def run_test(executable):
    result = subprocess.run([f"./{executable}"], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Test {executable} failed:\n{result.stderr}")
    else:
        print(f"Test {executable} passed:\n{result.stdout}")

def main():
    test_files = [
        "tests/test_init.cpp",
        "tests/test_moving_up.cpp",
        "tests/test_moving_downcpp",
        "tests/test_moving_left.cpp",
        "tests/test_moving_right.cpp",
        "tests/test_finish.cpp"
    ]

    for test_file in test_files:
        executable = compile_test(test_file)
        if executable:
            run_test(executable)
            os.remove(executable)

if __name__ == "__main__":
    main()
