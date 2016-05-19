#Brukiewicz Mikołaj Wojciech

Wpadłem na pomysł (oczywiście całkowicie nie będąc zainspirowanym bitwą Słowian) stworzenia symulacji **Gladiatora** walczącego o wolność niczym Russell Crowe w filmie Gladiator. 

Na początku program tworzyłby naszego **gladiatora** wybierając mu imię, ustalając liczbę hp (trochę większą niż przeciwników bo jak wiadomo główni bohaterowie mogą biegać z dziesięcioma strzałami w plecach), wartości ataku, obrony oraz parametru szczęścia (którego **przeciwnicy** nie będą posiadać, ponieważ tylko główni bohaterowie posiadają takie bonusy). **Gladiator** aby wywalczyć sobie wolność musi zwyciężyć w pięciu walkach:

- pierwsze 3 to **pojedynki** z innymi **Gladiatorami**, z czego każdy kolejny po wylosowaniu statystyk będzie dostawał 10% boosta do statystyk, aby uczynić walkę trudniejszą dla głównego bohatora tj. pierwsza walka - przeciwnik ma normalne statystyki, druga walka - 10% boosta, trzecia - 20% boosta

- czwarta to walka przeciwko **dzikim zwierzętom**, które będą posiadać śmiesznie wysoką wartość ataku, sporo hp, ale stosunkowo niską obronę

- ostatnia, piąta walka, to pojedynek z **centurionem**, który nie dość że będzie posiadał wysokie statystyki to po zbiciu go poniżej 30% hp dostanie enrage który zboostuje jego statystyki o 40%.

Jeżeli Maximus zwycięży pięć walk to wygrywa wolność, a jak nie to Requiescat in Pace.

## Słowo o statystykach

### HP

główny bohater będzie posiadał ich od 150-225, pozostali gladiatorzy 70-120, zwierzęta 100-150, centurion tak samo jak bohater. Żeby zwiększyć szanse naszego bohatera po każdym pojedynku dostanie on nagrodę w postaci wyleczenia 20% całkowitego hp

### Atak 

wartość 20-50 (zwierzaki dostaną więcej, gladiatorzy troszkę mniej)

###Obrona

wartość 50-80 (zwierzaki dostaną, mniej, gladiatorzy raczej podobnie) działa to na takiej zasadzie: Atak Maximusa wynosi 40, a obrona Corneliusa 80 -> dzielimy wartość ataku przez wartość obrony 40/80=1/2 - to jest procent wartości ataku Maximusa jaką Cornelius dostanie w postaci obrażeń

### Szczęście
wartość 10-25, żeby zobrazować o co mi chodzi oto przykład: w trakcie ataku Corneliusa zostanie wylosowana szansa powodzenia ataku (jakoś od 20 do 100), np 60, jeżeli parametr szczęścia Maximusa pomnożony przez 3 będzie większy niż szansa powodzenia ataku Corneliusa, to Maximus w iście Holywoodzkiej scenie uniknie wszystkich obrażeń.

