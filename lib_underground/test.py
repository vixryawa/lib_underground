import ctypes
lib = ctypes.CDLL('./lib_underground.dll')

#создаем обычные станции
s1 = lib.create_casstation(4, 2000, 'Vykhino')
s2 = lib.create_casstation(6, 1500, 'Kuzminki')
s5 = lib.create_casstation(7, 500, 'Tekstilschiki')
s6 = lib.create_casstation(2, 9000, 'Borovitskaya')
s7 = lib.create_casstation(3, 10000, 'Serpukhovskaya')

#проверяем функции получения номера и траффика
n = lib.get_n(s1)
traf = lib.get_traf(s1)
print(n, traf)

#создаем и соединяем станции пересадки (т.е. создаем пересадку)
t1 = lib.create_transstation(7, 10000, 'Pushinskaya')
t2 = lib.create_transstation(1, 12000, 'Chekhovskaya')
transf = lib.create_transfer(t1, t2, 4, 8000)

#создаем первую линию и добавляем в нее станции
line1 = lib.create_line()
lib.add_station(line1, s1, 0)
lib.add_station(line1, s2, 3)
lib.add_station(line1, s5, 7)
lib.add_station(line1, t1, 12)

#проверяем время между станциями на ветке
tb1 = lib.time_between(line1, s2, s5)
tb2 = lib.time_between(line1, s1, s2)
tb3 = lib.time_between(line1, s1, t1)
print(tb1, tb2, tb3)

#создаем метро и вторую ветку
subway = lib.create_subway()
line2 = lib.create_line()
#добавляем обе ветки к метро и пересадку между ними
lib.add_line(subway, line1)
lib.add_line(subway, line2)
lib.add_transf(subway, line1, line2, transf)

#добавляем станции на вторую ветку через метро
lib.add_stat_to_line(subway, t2, 0, line2)
lib.add_stat_to_line(subway, s6, 4, line2)
lib.add_stat_to_line(subway, s7, 9, line2)
tb4 = lib.time_between(line2, t2, s7)
print(tb4)
