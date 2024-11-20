# Book Nixie Alarm

Progetto per il regalo di compleanno di Josi,
si compone di un libro di legno con inserito sul fianco un tupo nixie in-4 per segnare l'ora e un carillon mangia nastro da 30 note da usare come sveglia.

## Arduino pro mini
Il tutto è gestito da un arduino pro mini modificato con un MCP1700 per l'alimentazione in low power e una batteria 18650.
Per la modifica low power ho usato questa guida [arduino pro low power](https://www.the-diy-life.com/making-an-ultra-low-power-arduino-pro/)

## Wood book

Link libro [link libro](https://boxes.hackerspace-bamberg.de/FlexBook?FingerJoint_style=rectangular&FingerJoint_surroundingspaces=2.0&FingerJoint_bottom_lip=0.0&FingerJoint_edge_width=1.0&FingerJoint_extra_length=0.0&FingerJoint_finger=2.0&FingerJoint_play=0.0&FingerJoint_space=2.0&FingerJoint_width=1.0&Flex_stretch=1.05&Flex_connection=1.0&Flex_distance=0.5&Flex_width=5.0&x=160&y=52&h=240&latchsize=8&recess_wall=0&thickness=4.0&format=svg&tabs=0.0&qr_code=0&debug=0&labels=0&labels=1&reference=100.0&inner_corners=loop&burn=0.1&language=en&render=0)

Link libro con mie misure: [link libro mie misure](https://boxes.hackerspace-bamberg.de/FlexBook?FingerJoint_style=rectangular&FingerJoint_surroundingspaces=2.0&FingerJoint_bottom_lip=0.0&FingerJoint_edge_width=1.0&FingerJoint_extra_length=0.0&FingerJoint_finger=2.0&FingerJoint_play=0.0&FingerJoint_space=2.0&FingerJoint_width=1.0&Flex_stretch=1.05&Flex_connection=1.0&Flex_distance=0.5&Flex_width=5.0&x=160&y=52&h=240&latchsize=8&recess_wall=0&thickness=4.0&format=svg&tabs=0.0&qr_code=0&debug=0&labels=0&labels=1&reference=100.0&inner_corners=loop&burn=0.1&language=en&render=1)

## Carillon

link carillon [carillon amazon](https://www.amazon.it/Carillon-manovella-movimento-creazione-artistica/dp/B08THCWNM8?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1XZ5GGZ021NRM&dib=eyJ2IjoiMSJ9.QQzVAgjMw9S7xzMlTWYozuvTzHghxjq6gpPHIJbElUKYlRqOrWiB-ASZT292nSN9vbmHCeorgpN6E38NXfF6hXoT529afymN0UDgZdS8ddOfWbPfle22UvW4tH8GHeCSwAv-aD0uYPSB_r9wcMWTPvVaHDnwHklei9ATIeY-n9Vt__DJh8ZmLgjCpfQ2-i_SxnxUw2VMucAzHEvtzzsEBB-xLfolCiQMPv8noNIDaZgrB_BB-Iqy563y3RDKX4-zBI13RX1uAisz7-rbu-GQybi77gVCVyluD8ARI00yeX4.IGsIalEeG8NRPCMl236Fyt45IoXqPEX0mPGQ_ATadh4&dib_tag=se&keywords=30+note+carillon&nsdOptOutParam=true&qid=1732109487&sprefix=30+note+carillon%2Caps%2C129&sr=8-7) secondo me si trova suo 20 euro.

per muovere il carillon ho usato un motore che va circa a 2V,
ho tagliato la manovellina e creata una puleggia per il movimento: la misura è 22mm ma andrebbe meglio lievemente più grande, tipo 24mm.

Per il controllo del nastro ho usato un sensore ir, che per non consumare, controllo con un 2N2222.

## Carillon Motor
per la gestione energetica del motore ho usato un dc-dc step down con collegato in parallelo al suo potenziometro, un altro da 10k intallato al lato del libro per scegliere la velocita della canzone in modo comodo.
per non consumare ho connesso il dc-dc ad un mosfet.

Flusso Motore: 3.9V Battery -> arduino -> mosfet -> dc-dc -> motor


## Nixie
per la gesione del nixie in-4 ho usato uno step-up NCH6100HV [NCH6100HV](https://www.amazon.it/dp/B075FBYWH1?ref=ppx_yo2ov_dt_b_fed_asin_title) per usarlo ho usato un dc-dc step up [step-up](https://www.amazon.it/dp/B09Z2B3LTL?ref=ppx_yo2ov_dt_b_fed_asin_title)
per non consumare ho connesso il dc-dc ad un mosfet connesso ad un transistor 2N2222.

Flusso Nixie: 3.9V Battery -> arduino -> 2N2222 -> mosfet -> dc-dc -> NCH6100HV -> nixie -> driver k155id1 -> arduino


## Settings selector
Per selezionare le opzioni del codice ho usato un potenziometro da 20K, ma anche 50K andrebbe bene, e per non consumare si attiva con un GPIO messo in HIGH.

## Input touch
Per la gestione dell'input con interrupt ho creato un sensore touch con 2 sonde usando 2 BC547 e una resistenza da 5.6M e una da 100K o 170K

## RTC DS3231
Ho usato un rtc [DS3231](https://www.amazon.it/dp/B07QFLD5B6?ref=ppx_yo2ov_dt_b_fed_asin_title), modificato per fare low power con questa guida [DS3231 low power](https://sites.google.com/site/wayneholder/time-based-and-low-power-techniques-for-arduino).

## Solar panel
Per essere eco con un nixie, (hahahhahaha) ho messo un pannello solare [solar panel](https://www.amazon.it/gp/product/B073XKPWY7/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) da 5V, 500mAh, 2.5W.
Ho collegato il pannello solare e la batteria con un [solar lipo charger](https://www.amazon.it/gp/product/B08C521Y3P/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) che ho connesso ad un connettore type C a pannello al lato del libro.

## Battery
Ho usato una batteria 18650 con un porta batteria apposta.

## Battery check
Per il check della tensione batteria ho usato un partitore tra 150K e 35K circa pilotato con un 2N2222 per non consumare.


