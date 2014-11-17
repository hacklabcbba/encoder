#define enc1 52
#define enc2 53
#define led 13

struct encoder_unit{
    uint8_t f1;
    uint8_t f2;
};

encoder_unit steps[4];

void setup(){

    steps[0].f1 = 0;
    steps[0].f2 = 1;

    steps[1].f1 = 0;
    steps[1].f2 = 0;

    steps[2].f1 = 1;
    steps[2].f2 = 0;

    steps[3].f1 = 1;
    steps[3].f2 = 1;
    /*
    pinMode(enc1, INPUT);    
    digitalWrite(enc1, HIGH);

    pinMode(enc2, INPUT);    
    digitalWrite(enc2, HIGH);
    */

    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    Serial.begin(9600);
}

void loop(){
    uint8_t s1, s2, i, last;
    uint8_t next, prev;
    /*
    int s1,s2;
    
    s1 = digitalRead(enc1);
    s2 = digitalRead(enc2);
    Serial.print(s1);
    Serial.print(" ");
    Serial.print(s2);
    Serial.print("\n");
    delay(100);
    */
    /*
    for(i = 0; i < 4; i++){
        if(s1 == steps[i].f1 && s2 == steps[i].f2){
            last = i;
        }
    }*/
    i = 0;
    while(1){
        s1 = digitalRead(enc1);
        s2 = digitalRead(enc2);
        next = i < 3 ? i + 1: 0; 
        prev = i > 0 ? i - 1: 3;
        if(s1 == steps[next].f1 && s2 == steps[next].f2){
            if(i < 3) 
                i++;
            else
                i = 0;
            Serial.write("Adelante\n");
        }
        if(s1 == steps[prev].f1 && s2 == steps[prev].f2){
            if(i > 0) 
                i--;
            else
                i = 3;
            Serial.write("Atras\n");
        }
    }
    /*
    if(digitalRead(enc1) == 0){
        digitalWrite(led, HIGH);
        Serial.write("HIGH\n");
    }else{
        digitalWrite(led, LOW);
        Serial.write("LOW\n");
    }*/
}
