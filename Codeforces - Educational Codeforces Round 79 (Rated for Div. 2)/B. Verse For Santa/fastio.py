'''
 # @ Author: Lakshya Singh
 # @ Create Time: 2020-11-29 11:22:27
 # @ Modified by: Target_X
 # @ Modified time: 2020-11-29 16:59:13
 # @ Description:
 '''

def targetx():
     _, s = [int(x) for x in input().split()]
     arr = [int(x) for x in input().split()]
     curr = 0
     for (i,x) in enumerate(arr):
          if x > arr[curr]:
               curr = i
          s -= arr[i]
          if s < 0:
               break
     if s >= 0:
          curr = -1
     print(curr+1)



if __name__ == "__main__":
     t = int(input())
     for z in range(t):
          targetx()
