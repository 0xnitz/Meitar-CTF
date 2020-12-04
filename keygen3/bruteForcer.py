import random
import string
import sys

charset = '0123456789ABCDEF'
rnd_chr = lambda : random.choice(charset)

def lock1():
    key = ''

    offset = 0
    low = 2
    offset_max = 4

    for x in range(16):
        ch = rnd_chr()
        while ord(ch) % (offset + low) != 0:
            ch = rnd_chr()

        key += ch
        offset = ((offset + 1) % offset_max)

    return key

def lock1_check(key):
    offset = 0
    low = 2
    offset_max = 4

    for x in range(16):
        if ord(key[x]) % (offset + low) != 0:
            return False

        offset = ((offset + 1) % offset_max)

    return True

class nibb:
    def __init__(self, data):
        self.data = data
        self.value = self.calc_val()

    def calc_val(self):
        y = 0
        
        for x in range(0, len(self.data), 2):
            y += ord(self.data[x]) ^ ord(self.data[x + 1])

        return y
        

def lock2():
    goods = []

    gen_nibble = lambda : ''.join([rnd_chr() for x in range(8)])

    lst1 = [nibb(gen_nibble()) for x in range(100)]
    lst2 = [nibb(gen_nibble()) for x in range(100)]

    lst1.sort(key = lambda x: x.value)
    lst2.sort(key = lambda x: x.value)

    for x in range(len(lst1)):
        for y in range(len(lst2)):
            if abs(lst2[y].value - lst1[x].value) == 5:
                if lst2[y].value - lst1[x].value == 5:
                    goods.append(lst1[x].data + lst2[y].data)
                else:
                    goods.append(lst2[y].data + lst1[x].data)

                break

            if lst2[y].value - lst1[x].value < 5:
                y += 1
                continue
            else: #lst2[y] - lst[1] > 5
                break

    return goods


def lock2_check(key):
    nib1, nib2 = nibb(key[: 8]), nibb(key[8 : 16])

    if abs(nib2.value - nib1.value) == 5:
        if nib2.value - nib1.value == 5:
            return True

    return False

def lock3_check(key):
    return sum(map(ord, key)) % 7 == 0

def lock3():
    gen_rnd = lambda : ''.join([rnd_chr() for x in range(16)])
    k = gen_rnd()

    while not(lock3_check(k)):
        k = gen_rnd()

    return k

lock2_check('2BD2D6DFB3D2430A')

if len(sys.argv) == 1:

    lst = set()

    while len(lst) < 100000:
        for x in lock2():
            lst.add(x) 

    print('\n'.join(lst))

elif sys.argv[1] == '-j':
    def comb_set_func(fname, set1, func):
        with open(fname) as f:
            for x in f.read().split():
                if func(x):
                    set1.add(x)

        return set1

    lsts = set()

    chk_fnc = lambda x: lock1_check(x) and lock2_check(x)

    comb_set_func('lock1', lsts, chk_fnc)
    comb_set_func('lock2', lsts, chk_fnc)

    print('\n'.join(list(lsts)))

elif sys.argv[1] == '-t':
    chk_fnc = lambda x: lock1_check(x) and lock2_check(x) and lock3_check(x)
    
    lsts = set()
    lst12 = []

    with open('lock12') as f:
        lst12 += f.read().split()

    for x in lst12:
        if chk_fnc(x):
            lsts.add(x)

    del lst12

    border = 30000

    while len(lsts) < 2000:
        print('{0} %'.format(100*(len(lsts) / 2000)), end='\r', file=sys.stderr)
        lst_chk = [lock1() for x in range(border)]
        lst2 = []

        while len(lst2) < border:
            for x in lock2():
                lst2.append(x)

        lst_chk += lst2
        del lst2

        lst3 = [lock3() for x in range(border)]
        
        lst_chk += lst3
        del lst3

        # After gen
        for x in lst_chk:
            if chk_fnc(x):
                lsts.add(x)

    print('\n'.join(list(lsts)))


