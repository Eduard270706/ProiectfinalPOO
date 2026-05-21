Tema 3 a proiectului meu este practic o continuare a temei 2, doar ca aici am incercat sa fac proiectul mai bun si sa adaug lucruri noi pe care le-am invatat la programare orientata pe obiecte. Proiectul este despre un campionat de fotbal si are clase pentru jucatori, echipe, meciuri, etape si campionat. Fata de tema 2, acum codul este mai bine organizat si are mai multe functionalitati.

In tema 2 aveam deja baza proiectului facuta. Puteam sa creez echipe, jucatori si meciuri intre echipe. Totul mergea bine, dar era mai simplu si nu aveam foarte multe concepte avansate. In tema 3 am pastrat ideea principala, dar am incercat sa fac proiectul mai interesant si mai apropiat de cum sunt facute proiectele reale.

Cea mai mare diferenta fata de tema 2 este faptul ca am transformat clasa Echipa intr-o clasa template. Din cauza asta am eliminat fisierul cpp si am scris tot direct in header. La inceput mi s-a parut putin ciudat sa scriu tot acolo, dar dupa am inteles ca asa functioneaza template-urile in C++. Avantajul este ca acum clasa poate fi folosita mai usor cu mai multe tipuri de obiecte si proiectul devine mai flexibil. Practic, daca vreau sa schimb ceva sau sa adaug lucruri noi, pot face asta mai simplu fara sa stric restul codului.

O alta modificare importanta este faptul ca am adaugat design pattern-ul Factory prin clasa JucatorFactory. Rolul acestei clase este sa creeze jucatorii automat, fara sa mai scriu de fiecare data cod separat in main. In proiect exista mai multe tipuri de jucatori, cum ar fi Atacant, Fundas, Mijlocas si Portar. Cu Factory-ul, codul este mai curat si mai usor de inteles. Mi s-a parut util pentru ca evita foarte multe if-uri si face programul mai organizat.

Pe langa asta am adaugat si design pattern-ul Decorator. Aici am facut clasele Decorator, JucatorForma si JucatorObosit. Ideea este ca un jucator poate avea diferite stari fara sa modific direct clasa de baza. De exemplu, un jucator poate fi intr-o forma foarte buna sau poate fi obosit dupa mai multe meciuri. In functie de starea lui, performanta poate sa creasca sau sa scada. Mi s-a parut o chestie interesanta pentru ca adauga mai mult realism proiectului si in acelasi timp face codul mai bun.

Clasa Jucator este baza pentru toate tipurile de jucatori. Din ea mostenesc Atacant, Fundas, Mijlocas si Portar. Fiecare tip de jucator are caracteristici diferite. De exemplu, atacantul este mai bun pe atac, iar portarul are alte statistici. Mostenirea ajuta mult pentru ca nu trebuie sa repet acelasi cod de fiecare data pentru fiecare clasa.

Clasa Meci se ocupa de meciurile dintre doua echipe. Aici sunt folosite echipele si jucatorii creati anterior. Clasa Etapa grupeaza mai multe meciuri, iar clasa Campionat coordoneaza tot sezonul. Practic, toate clasele sunt legate intre ele si impreuna formeaza simularea campionatului.
Am folosit si exceptii prin fisierul Exceptii.h. Acestea ajuta programul sa gestioneze erorile mai bine. De exemplu, daca se introduc date gresite sau apare o problema, programul poate afisa un mesaj clar in loc sa se inchida direct. Consider ca asta face proiectul mai stabil si mai bine facut.

In main.cpp am demonstrat toate functionalitatile proiectului. Acolo sunt create echipele, jucatorii si meciurile. Tot acolo se vede si cum functioneaza Factory si Decorator. Main-ul este practic locul unde toate clasele lucreaza impreuna.
Un alt lucru pe care l-am observat la tema 3 este faptul ca proiectul este mai bine organizat fata de tema 2. Inainte, multe lucruri erau facute mai direct si codul era mai simplu, dar acum fiecare clasa are rolul ei clar. Mi se pare ca asta ajuta mult atunci cand proiectul devine mai mare, pentru ca poti modifica o parte fara sa incurci restul programului.

De asemenea, prin proiect am inteles mai bine cum functioneaza mostenirea si polimorfismul in C++. Acum toate tipurile de jucatori pot fi folosite prin clasa de baza Jucator si asta face codul mai simplu. Mi se pare mai usor de lucrat asa si mai ok decat sa scriu cod separat pentru fiecare tip de jucator.
Mi s-a parut interesant si faptul ca design pattern-urile chiar sunt utile, nu doar teorie. La inceput pareau destul de grele si complicate, dar dupa ce le-am folosit in proiect am vazut ca ajuta mult. Factory-ul simplifica partea de creare a obiectelor, iar Decorator-ul permite adaugarea unor functionalitati noi fara sa modific clasele principale.

Consider ca tema 3 este mult mai buna fata de tema 2 si arata clar ca proiectul a evoluat. Chiar daca ideea principala a ramas aceeasi, acum aplicatia este mai apropiata de modul in care sunt facute proiectele mai serioase. In plus, am invatat mai multe despre organizarea codului si despre cum pot fi folosite conceptele de POO intr-un proiect mai mare.

Per total, tema 3 este mai complexa fata de tema 2 si contine mai multe concepte importante din C++. Cele mai mari diferente sunt transformarea clasei Echipa in template si adaugarea pattern-urilor Factory si Decorator. Cred ca aceste schimbari fac proiectul mai interesant, mai bine organizat si mai usor de extins pe viitor.

Bibliografie:

Link site ajutor creare design pattern decorator:https://refactoring.guru/design-patterns/decorator/cpp/example
