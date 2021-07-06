class Variable:
  def __init__(self, cnt, length, prefix, suffix):
    self.cnt = cnt
    self.length = length
    self.prefix = prefix
    self.suffix = suffix


def CountOccurrences(string, substring):
  
    count = 0
    start = 0
    while start < len(string):
  
        pos = string.find(substring, start)
  
        if pos != -1:
            start = pos + 1
            count += 1
        else:
            break

    return count

def solve():
	n = int(input())
	m = {}
	ans = ""

	for _ in range(n):
		instruction = input().split()
		# print(instruction)
		if instruction[1] == ":=":
			var = instruction[0]
			string = instruction[2]

			cnt = CountOccurrences(string,"haha")
			length = len(string)
			prefix = string
			suffix = string
			m[var] = Variable(cnt,length,prefix,suffix)


		else:
			var, one, two = instruction[0], instruction[2], instruction[4]
			varOne, varTwo = m[one], m[two]
			oneSuffix = varOne.suffix if len(varOne.suffix) < 3 else varOne.suffix[:3]
			twoPrefix = varTwo.prefix if len(varTwo.prefix) < 3 else varTwo.prefix[-3:]

			cnt = varOne.cnt + varTwo.cnt + CountOccurrences(oneSuffix + twoPrefix, "haha")
			length = varOne.length + varTwo.length
			if varOne.length >= 3 and varTwo.length >= 3:
				prefix = varOne.prefix[:3]
				suffix = varTwo.suffix[-3:]
			elif varOne.length <= 3 and varTwo.length <= 3:
				string = varOne.prefix + varTwo.suffix
				prefix = string if length < 5 else string[:5]
				suffix = string if length < 5 else string[-5:]

			m[var] = Variable(cnt,length,prefix,suffix)
			ans = m[var] 

	# print(ans)
	print(ans.cnt)

tc = int(input())
for _ in range(tc):
	solve()