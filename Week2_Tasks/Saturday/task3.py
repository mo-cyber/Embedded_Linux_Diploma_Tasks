lst = ['line', '5', 'task', '3']
f = open('textfile.txt', 'a')
f.write('\n')
f.write(' '.join(lst))
f.close()