with import <nixpkgs> {};
  mkShell {
    nativeBuildInputs = [cmake pkg-config];
    buildInputs = [libX11];
  }
