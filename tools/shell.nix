{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    nativeBuildInputs = with pkgs.buildPackages; [
        pkg-config
        cmake
    ];
    buildInputs = with pkgs.buildPackages; [
      SDL2
    ];
    shellHook = 
      ''
        zsh
      '';
}
