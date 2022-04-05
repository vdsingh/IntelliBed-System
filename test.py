from hx711 import HX711

hx = HX711(5,6)

hx.reset()
print(hx.get_weight())