// Hi Emacs, this is -*- mode: c++; tab-width: 6; indent-tabs-mode: nil; c-basic-offset: 6 -*-

#include "version.h"

#include <string>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define TELETRAFFIC_VERSION_MAJOR 0
#define TELETRAFFIC_VERSION_MINOR 5
#define TELETRAFFIC_VERSION_MICRO 0
#define TELETRAFFIC_PUBLICATION_DATE "Jun 21 2016"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int teletraffic::VersionMajor() {
      return TELETRAFFIC_VERSION_MAJOR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int teletraffic::VersionMinor() {
      return TELETRAFFIC_VERSION_MINOR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int teletraffic::VersionMicro() {
      return TELETRAFFIC_VERSION_MICRO;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* teletraffic::VersionString() {
      return STR(TELETRAFFIC_VERSION_MAJOR) "." STR(TELETRAFFIC_VERSION_MINOR) "." STR(TELETRAFFIC_VERSION_MICRO);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool teletraffic::VersionCheck(int major, int minor, int micro) {
      if (major != TELETRAFFIC_VERSION_MAJOR) {
            // Es una rama distinta, no es compatible
            return false;
      }
      if (minor > TELETRAFFIC_VERSION_MINOR) {
            // El número minor mínimo exigido es mayor que la de esta biblioteca
            return false;
      } else if (minor == TELETRAFFIC_VERSION_MINOR) {
            if (micro > TELETRAFFIC_VERSION_MICRO) {
                  // El número micro mínimo exigido es mayor que la de esta biblioteca (dentro de la rama major.minor)
                  return false;
            }
      }
      return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* teletraffic::BuildDate() {
      return __DATE__ " " __TIME__;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* teletraffic::PublicationDate() {
      return TELETRAFFIC_PUBLICATION_DATE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
