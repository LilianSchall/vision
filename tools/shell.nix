{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
    # use of nativeBuildInputs because I want to setup an environment for
    # the whole shell
    nativeBuildInputs = with pkgs.buildPackages; [
        SDL2
        SDL2_image
        SDL2_gfx
        SDL2_ttf
        SDL2_mixer
    ];
    shellHook = 
      ''
        zsh
      '';
}
