# 1 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
// "Copyright 2021 Francisco Aguilera"

# 4 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2

# 6 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 7 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 8 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 9 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 10 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2

falven::ad::HttpServer
    irrigationServer( // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        80u);
falven::ad::MotorDriver
    pumpDriver( // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        1u, 2u, 3u);
falven::ad::WifiModule
    wiFiModule( // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        "falven", "kyranano", "Fran-IRRIGATION");

void setup() {
  debug.begin(9600U);;
  debug << millis() << "ms: " << "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" << ':' << 23 << ' ' << __PRETTY_FUNCTION__ << endl;;

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }
