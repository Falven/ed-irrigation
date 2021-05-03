# 1 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
// "Copyright 2021 Francisco Aguilera"

# 4 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2

# 6 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 7 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 8 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 9 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2
# 10 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" 2

using namespace falven::ad;

MotorDriver pumpDriver(1u, 2u,
                       3u);
WifiModule wiFiModule("falven", "kyranano", "Fran-IRRIGATION");
HttpServer irrigationServer(80u);

void setup() {
  debug.begin(9600u);;
  debug << millis() << "ms: " << "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino" << ':' << 20 << ' ' << __PRETTY_FUNCTION__ << endl;;

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }
