from hx711 import HX711
from firebase import Firebase
import time

config = {
  "apiKey": "AIzaSyBqmtDdXcCLp4ODEgtkelMj7QWEixxSVOY",
  "authDomain": "intelli--bed.firebaseapp.com",
  "databaseURL": "https://intelli--bed-default-rtdb.firebaseio.com/",
  "storageBucket": "intelli--bed.appspot.com"
}
prevTime = time.time()
data = {
  "mean":4,
  "stdev":34,
  "numPeaks":2
}
fb = Firebase(config)
fb.clearTable()

# hx = HX711(5,6)
# hx.reset()
# hx.set_reference_unit()
# print(hx.get_weight())