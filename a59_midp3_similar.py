def sim(a, b):
  if len(a) == 1:
    if a == b:
      return True
    else: 
      return False
  m = len(a)//2
  return (sim(a[:m], b[:m]) and sim(a[m:], b[m:])) or (sim(a[:m], b[m:]) and sim(a[m:], b[:m]))
  
aa = input()
bb = input()
if sim(aa,bb):
  print("YES")
else:
  print("NO")
