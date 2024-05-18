# default.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
    pkgs.sqlite
    pkgs.sfml
    pkgs.qt5.qtbase
    pkgs.qt5.qtwebengine
  ];
}
