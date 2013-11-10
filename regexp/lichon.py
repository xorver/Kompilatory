import os
import sys
import re
import codecs

def flat(listToFlat):
	return reduce(lambda l1,l2:(isinstance(l2,list) and l1.extend(l2)) or l1,listToFlat,[])

def processFile(filepath):
	fp = codecs.open(filepath, 'rU', 'iso-8859-2')
	content = fp.read()
	fp.close()
	autor = re.compile('<META NAME="AUTOR" CONTENT="(.*?)">').search(content).group(1)
	dzial = re.compile('<META NAME="DZIAL" CONTENT="(.*?)">').search(content).group(1)
	slowa_kluczowe = re.compile('<META NAME="KLUCZOWE_\d*?" CONTENT="(.*?)">').findall(content)
	tekst = re.sub('<.*?>','',re.compile('<P>(.*)<META.*?>',re.DOTALL).search(content).group())
	zdania = re.compile('(?:(?<=\. )|(?<=^))[A-Z].+?(?:(?=\.\s*$)|(?=\.\s+[A-Z])|(?=[?!]+))',re.MULTILINE).findall(tekst)
	skroty = flat( map(lambda zdanie: re.compile(' [A-Za-z]{1,3}\.').findall(zdanie),zdania) ) 
	calkowite = filter(lambda number: int(number)>=-32768 and int(number)<=32767, re.compile('-?\d+(?!\.?\d)').findall(tekst))
	zmiennoprzecinkowe = re.compile('\s-?(?:\d+[.]\d*|\d*[.]\d+)(?:e[+-]?\d+)?(?!(\d)*\.\d)').findall(tekst)
	daty = map(lambda l: l[0],re.compile('((?:0[1-9]|[12][0-9])(?P<sep1>[-/.])02(?P=sep1)\d\d\d\d'+
						'|'+'(0[1-9]|[12][0-9]|30)(?P<sep2>[-/.])(?:0[469]|11)(?P=sep2)\d\d\d\d'+
						'|'+'(?:0[1-9]|[12][0-9]|3[01])(?P<sep3>[-/.])(?:0[13578]|1[02])(?P=sep3)\d\d\d\d'+
						'|'+'\d\d\d\d(?P<sep4>[-/.])(?:0[1-9]|[12][0-9])(?P=sep4)02'+
						'|'+'\d\d\d\d(?P<sep5>[-/.])(?:0[1-9]|[12][0-9]|30)(?P=sep5)(?:0[469]|11)'+
						'|'+'\d\d\d\d(?P<sep6>[-/.])(?:0[1-9]|[12][0-9]|3[01])(?P=sep6)(?:0[13578]|1[02]))'
						).findall(tekst))
	daty=map(lambda l:re.sub('[/-]','.',l),daty)
	daty=map(lambda l:re.sub(r'(\d\d\d\d)\.(\d\d)\.(\d\d)',r'\g<2>.\g<3>.\g<1>',l),daty)
	maile = re.compile('\w+@\w+(?:\.\w+)+').findall(content)
	print("autor:" + autor)
	print("dzial:"+ dzial)
	print("slowa kluczowe:"+str(slowa_kluczowe))
	print("liczba zdan:"+str(len(zdania)))
	print("liczba skrotow:"+str(len(set(skroty))))
	print("liczba liczb calkowitych z zakresu int:"+str(len(set(calkowite))))
	print("liczba liczb zmiennoprzecinkowych:"+str(len(set(zmiennoprzecinkowe))))
	print("liczba dat:"+str(len(set(daty))))
	print("liczba adresow email:"+str(len(set(maile))))
	print("\n")



try:
    path = sys.argv[1]
except IndexError:
    print("Brak podanej nazwy katalogu")
    sys.exit(0)


tree = os.walk(path)

for root, dirs, files in tree:
    for f in files:
        if f.endswith(".html"):
            filepath = os.path.join(root, f)
            processFile(filepath)