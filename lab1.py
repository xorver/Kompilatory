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
	tekst = re.sub('<.*?>','',re.compile('<B>(.*)</B>',re.DOTALL).search(content).group())
	#print tekst 
	zdania = re.compile('(?:(?<=\. )|(?<=^))[A-Z].+?(?:(?=\.\s*$)|(?=\.\s+[A-Z]))',re.MULTILINE).findall(tekst)
	skroty = flat( map(lambda zdanie: re.compile(' [A-Za-z]+?\.').findall(zdanie),zdania) ) 
	calkowite = re.compile('\d+(?![.,] ?\d)').findall(tekst)
	zmiennoprzecinkowe = re.compile('\d+[.,] ?\d+').findall(tekst)
	MIESIAC = '(?:[sS]tycz|[lL]ut|[mM]ar|[kK]wie|[mM]aj|[cC]zerw|[lL]ip|[sS]ierp|[wWrze|[pP]a|[lL]ist|[gG]rud)[a-z]+'
	DZIEN_I_MIESIAC = '(?:\d\d? ' + MIESIAC+')'
	ROK = '\d\d\d\d (?:r\.|roku)'
	daty = re.compile(DZIEN_I_MIESIAC+' '+ROK+'|'+DZIEN_I_MIESIAC+'|'+MIESIAC+' '+ROK+'|'+ROK).findall(tekst)
	maile = re.compile('\w+@\w+(?:\.\w+)*').findall(content)
	print("autor:" + autor)
	print("dzial:"+ dzial)
	print("slowa kluczowe:"+str(slowa_kluczowe))
	print("liczba zdan:"+str(len(zdania)))
	print("liczba skrotow:"+str(len(skroty)))
	print("liczba liczb calkowitych z zakresu int:"+str(len(calkowite)))
	print("liczba liczb zmiennoprzecinkowych:"+str(len(zmiennoprzecinkowe)))
	print("liczba dat:"+str(len(daty)))
	print("liczba adresow email:"+str(len(maile)))
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