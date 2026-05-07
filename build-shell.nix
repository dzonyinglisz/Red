with import <nixpkgs> {};
  mkShell {
    nativeBuildInputs = [cmake pkg-config];
    buildInputs = [libX11 libxrandr libxinerama libxcursor libxi mesa libGL libGLU];
  }
