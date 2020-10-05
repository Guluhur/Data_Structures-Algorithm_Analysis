#: selection_problem.py
from datetime import datetime
import random as rand

''' 找到一数组按从小到大排列后的第k个元素
 * @author Guluhur
 * @date 2020/10/5
 * @version 1.0
'''


def print_array(array: list):
    print("Array = [")
    for i in range(len(array)):
        print(array[i], end='\t')
        if (i+1) % 10 == 0:
            print("")
    print("]")


def select_soft(array: list, soft_length: int):
    for i in range(soft_length):
        idx = i
        for j in range(i + 1, len(array)):
            if array[idx] > array[j]:
                idx = j
        if idx != i:
            array[i], array[idx] = array[idx], array[i]


N = 8192
MAX = 1000
k = int(N / 2)
ary = []
rand.seed(11)
for i in range(N):
    ary.append(rand.randint(1, MAX))
# print_array(ary)
begin_t = datetime.now()
select_soft(ary, k)
end_t = datetime.now()
# print_array(ary)
print("Element[{}] = {}".format(k, ary[k - 1]))
print("Cost: {}ms".format(((end_t - begin_t).seconds * 1000 +
                           (end_t - begin_t).microseconds)/1000))
''' Output(50% match):
Element[4096] = 494
Cost: 448.91ms
'''  #: ~
