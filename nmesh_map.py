import sys

sum = 0
for line in sys.stdin:
    lineComps = line.strip().split()
    low_addr, high_addr = map(lambda x : int(x, 16), lineComps[0].split('-'))
    diff = high_addr - low_addr
    sum = sum + diff 
    print '0x%08x - 0x%08x = 0x%08x %6d kb   %s' % (high_addr, low_addr, diff, int(diff)/1024, lineComps[-1])

print '                          ----------'
print '    Mem map for process = %d bytes or %d kb (decimal)' % (sum, sum/1024)
print ' -----------------------------------------------------------------------------------------'
