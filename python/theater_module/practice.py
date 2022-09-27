import imp
from re import I
import theater_module
theater_module.prince(3) # 3명이서 영화
theater_module.prince_m(4) # 4명이서 조조할인 영화
theater_module.prince_s(5) # 5명이서 군인할인 영화

import theater_module as mv
mv.prince(3) # 3명이서 영화
mv.prince_m(4) # 4명이서 조조할인 영화
mv.prince_s(5) # 5명이서 군인할인 영화

from theater_module import *
prince(3) # 3명이서 영화
prince_m(4) # 4명이서 조조할인 영화
prince_s(5) # 5명이서 군인할인 영화

from theater_module import prince, prince_m
prince(3) # 3명이서 영화
prince_m(4) # 4명이서 조조할인 영화
prince_s(5) # 5명이서 군인할인 영화

from theater_module import prince_s as price 
price(5) # 5명이서 군인할인 영화