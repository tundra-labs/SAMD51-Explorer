
void dumpClockConfig(){
  Serial.println("SAMD51 Clock Config");
  for (uint8_t i=0;i<12;i++) {
    Serial.print("********** Clock ");
    Serial.print(i);
    Serial.println(" **********");
    if (GCLK->GENCTRL[i].bit.GENEN) {
      Serial.print("  Source: ");
      switch(GCLK->GENCTRL[i].bit.SRC) {
        case 0:
          Serial.println("XOSC 0 oscillator output");
          break;
        case 1:
          Serial.println("XOSC 1 oscillator output");
          break;
        case 2:
          Serial.println("Generator input pad (GCLK_IO)");
          break;
        case 3:
          Serial.println("Generic clock generator 1 output");
          break;
        case 4:
          Serial.println("OSCULP32K oscillator output");
          break;
        case 5:
          Serial.println("XOSC32K oscillator output");
          break;
        case 6:
          Serial.println("DFLL oscillator output");
          break;
        case 7:
          Serial.println("DPLL0 output");
          break;
        case 8:
          Serial.println("DPLL1 output");
          break;
        default:
          Serial.print("Unknown -> ");
          Serial.println(GCLK->GENCTRL[i].bit.SRC);
      }
      Serial.print("  Run in Standby: ");
      Serial.println(GCLK->GENCTRL[i].bit.RUNSTDBY);
      Serial.print("  Output Enabled: ");
      Serial.println(GCLK->GENCTRL[i].bit.OE);
      if (GCLK->GENCTRL[i].bit.DIVSEL) {
        Serial.print("  Division enabled by factor of: ");
        Serial.println(GCLK->GENCTRL[i].bit.DIV);
      }
      else{
        Serial.println("  Division Disabled");
      }
      Serial.println("  Connected Periprials:");
      for (uint8_t sink=0;sink<48;sink++) {
        if (GCLK->PCHCTRL[sink].bit.CHEN && GCLK->PCHCTRL[sink].bit.GEN == i) {
          switch(sink) {
            case 0:
              Serial.println("    -> OSCCTRL DFLL48");
              break;
          case 1:
              Serial.println("    -> OSCCTRL FDPLL0");
              break;
          case 2:
              Serial.println("    -> OSCCTRL FDPLL1");
              break;
          case 3:
              Serial.println("    -> OSCCTRL FDPLL0 32K");
              break;
          case 4:
              Serial.println("    -> EIC");
              break;
          case 5:
              Serial.println("    -> FREQM MSR");
              break;
          case 6:
              Serial.println("    -> FREQM REF");
              break;
          case 7:
              Serial.println("    -> SERCOM0 CORE");
              break;
          case 8:
              Serial.println("    -> SERCOM1 CORE");
              break;
          case 9:
              Serial.println("    -> TC1");
              break;
          case 10:
              Serial.println("    -> USB");
              break;
          case 11:
              Serial.println("    -> EVSYS11");
              break;
          case 12:
              Serial.println("    -> EVSYS12");
              break;
          case 13:
              Serial.println("    -> EVSYS13");
              break;
          case 14:
              Serial.println("    -> EVSYS14");
              break;
          case 15:
              Serial.println("    -> EVSYS15");
              break;
          case 16:
              Serial.println("    -> EVSYS16");
              break;
          case 17:
              Serial.println("    -> EVSYS17");
              break;
          case 18:
              Serial.println("    -> EVSYS18");
              break;
          case 19:
              Serial.println("    -> EVSYS19");
              break;
          case 20:
              Serial.println("    -> EVSYS20");
              break;
          case 21:
              Serial.println("    -> EVSYS21");
              break;
          case 22:
              Serial.println("    -> EVSYS22");
              break;
          case 23:
              Serial.println("    -> SERCOM2 CORE");
              break;
          case 24:
              Serial.println("    -> SERCOM3 CORE");
              break;
          case 25:
              Serial.println("    -> TCC0,");
              break;
              Serial.println("    -> TCC1");
              break;
          case 26:
              Serial.println("    -> TC2,");
              break;
              Serial.println("    -> TC3");
              break;
          case 27:
              Serial.println("    -> CAN0");
              break;
          case 28:
              Serial.println("    -> CAN1");
              break;
          case 29:
              Serial.println("    -> TCC2,");
              break;
              Serial.println("    -> TCC3");
              break;
          case 30:
              Serial.println("    -> TC4,");
              break;
              Serial.println("    -> TC5");
              break;
          case 31:
              Serial.println("    -> PDEC");
              break;
          case 32:
              Serial.println("    -> AC");
              break;
          case 33:
              Serial.println("    -> CCL");
              break;
          case 34:
              Serial.println("    -> SERCOM4 CORE");
              break;
          case 35:
              Serial.println("    -> SERCOM5 CORE");
              break;
          case 36:
              Serial.println("    -> SERCOM6 CORE");
              break;
          case 37:
              Serial.println("    -> SERCOM7 CORE");
              break;
          case 38:
              Serial.println("    -> TCC4");
              break;
          case 39:
              Serial.println("    -> TC6,");
              break;
              Serial.println("    -> TC7");
              break;
          case 40:
              Serial.println("    -> ADC0");
              break;
          case 41:
              Serial.println("    -> ADC1");
              break;
          case 42:
              Serial.println("    -> DAC");
              break;
          case 43:
              Serial.println("    -> I2S43");
              break;
          case 44:
              Serial.println("    -> I2S44");
              break;
          case 45:
              Serial.println("    -> SDHC0");
              break;
          case 46:
              Serial.println("    -> SDHC1");
              break;
          case 47:
              Serial.println("    -> CM4 TRACE");
              break;
          }
        }
      }
    }
    else {
      Serial.println("  is Disabled");
    }
  }
}
