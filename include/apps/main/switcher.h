#ifndef OSW_APP_APPSWITCHER_H
#define OSW_APP_APPSWITCHER_H

#include <osw_app.h>
#include <osw_hal.h>
#include <osw_ui.h>

#include <vector>

enum OswAppSwitcherType { SHORT_PRESS, LONG_PRESS };

class OswAppSwitcher : public OswApp {
 public:
  OswAppSwitcher(Button btn, OswAppSwitcherType type, bool enableAutoSleep, bool enableSleep, uint16_t* rtcAppIndex) {
    _btn = btn;
    _type = type;
    _enableAutoSleep = enableAutoSleep;
    _enableSleep = enableSleep;
    _rtcAppIndex = rtcAppIndex;
  }
  OswAppSwitcher(){};
  void setup(OswHal* hal);
  void loop(OswHal* hal);
  void stop(OswHal* hal);
  void paginationDisable();
  void paginationEnable();
  void registerApp(OswApp* app);
  ~OswAppSwitcher(){};

 private:
  void cycleApp(OswHal* hal);
  void sleep(OswHal* hal, boolean fromButton);
  Button _btn = BUTTON_1;
  OswAppSwitcherType _type = LONG_PRESS;
  std::vector<OswApp*> _apps;
  uint16_t* _rtcAppIndex;
  uint16_t _appCount = 0;
  bool _pagination = true;
  bool _paginationIndicator = false;
  bool _enableAutoSleep = false;
  bool _checked = false;
  bool _enableSleep;
  bool _doSleep = false;
  bool _doSwitch = false;
  long appOnScreenSince = 0;
};

#endif
