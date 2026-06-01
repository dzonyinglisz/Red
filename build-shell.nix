with import <nixpkgs> {};
  mkShell {
    # git + cacert are needed by CMake FetchContent to clone raylib/raygui at
    # configure time; gcc is the compiler.
    nativeBuildInputs = [cmake pkg-config git cacert gcc];
    buildInputs = [libX11 libxrandr libxinerama libxcursor libxi mesa libGL libGLU];
  }
