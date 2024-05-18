{ pkgs }: {
  deps = [
    pkgs.sqlite
    pkgs.qt5.qtbase
    pkgs.qt5.qtwebengine
    pkgs.sfml
  ];
}