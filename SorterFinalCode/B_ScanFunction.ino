void scanfun(void) {
  colorScan();
  pos5Color = pos4Color;
  pos4Color = parseColor();
  pos5Metal = metalDetect();

}
