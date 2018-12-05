def main():
    with open("input") as f:
        somma = 0
        res = []
        som = []
        i = 0
        for line in f:
            a = line.split()
            somma += int(a[0])
            res.append(int(a[0]))
            som.append(somma)
            if int(a[0]) in res[:i]:
                print("Prima occorrenza trovata: ", a[0], " cerco la prima occorrenza della frequenza")
                j = 0
                res_size = i
                while somma not in som[:i]:
                    somma += res[j]
                    som.append(somma)
                    
                    #aggiorno indice dei res
                    j += 1
                    #se sono out of bound di res riparto dall'inizio
                    if j > res_size:
                        j = 0  
                print(somma, '\n')
            #aggiorno indice di res e som
            i += 1            
if __name__ == "__main__":
    main()