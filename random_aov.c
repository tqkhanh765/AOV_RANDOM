#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))

int interface_vnm();
int interface_eng();
int rand_value(int min, int max);
void random(int choice);
void again();
void start();
void mix();
int mix_first(int a);
int mix_second(int b);
int mix_third(int b);
int mix_fourth(int b);
int mix_fifth(int b);

int choice;
int again_choice;
int n;
int max_value = 0;
int a,b,c,d,e;
int multiple;
int max_mix;
char first[200][30], second[200][30], third[200][30], fourth[200][30], fifth[200][30];


char dodon[][30] = {"Mina", "Baldum", "Gildur", "Skud", "Arum", "Grakk", "Maloch", "Taara", "Toro", "Ormarr", "Y'bneth", "Xeniel", "Wiro", "Cresht", "Arduin", "Lumburr", "Omega", "Max", "Dextra", "Roxie", "Ata", "Chaugnar", "Thane", "TeeMee"};
int max_dodon = (int)LENGTH_OF_ARRAY(dodon) - 1;
char dausi[][30] = {"Butterfly", "Yena", "Veres", "Trieu Van", "Zuka", "Airi", "Skud", "Amily", "Lu Bo", "Omen", "Maloch", "Florentino", "Taara", "Richter", "Qi", "Superman", "Astrid", "Volkath","Ryoma", "Wiro", "Errol", "Arduin", "Tachi", "Allain", "Rourke", "Zephys", "Yan", "Wonder Woman", "Dextra", "Roxie", "Arthur", "Kil'Groth", "Bijan"};
int max_dausi = (int)LENGTH_OF_ARRAY(dausi) - 1;
char satthu[][30] = {"Butterfly", "Liliana", "Nakroth", "Zuka", "Airi", "Ngo Khong", "Zill", "Zata", "Raz", "Quillen", "Murad", "Paine", "Qi", "Kriknak", "Astrid", "Volkath", "Ryoma", "Aoi", "Enzo", "Sinestrea", "Keera", "Zephys", "Yan", "Kaine", "The Flash", "Bright"};
int max_satthu = (int)LENGTH_OF_ARRAY(satthu) - 1;
char phapsu[][30] = {"Veera", "Krixi", "Mganga", "Kahlii", "Dieu Thuyen", "Azzen'Ka", "Aleister", "Natalya", "Jinna", "Ilumia", "Preyta", "Raz", "Lauriel", "Ignis", "Zill", "Tulen", "Liliana", "The Flash", "Marja", "D'arcy", "Ishar", "Dirak", "Zata", "Lorion", "Iggy", "Annette", "Sephera"};
int max_phapsu = (int)LENGTH_OF_ARRAY(phapsu) - 1;
char xathu[][30] = {"Valhein", "Violet", "Yorn", "Fennik", "Slimz", "Joker", "Tel'Annas", "Moren", "Lindis", "Wisp", "Elsu", "Hayate", "Capheny", "Celica", "Eland'orr", "Laville", "Thorne", "Erin"};
int max_xathu = (int)LENGTH_OF_ARRAY(xathu) - 1;
char trothu[][30] = {"Alice", "Chaugnar", "Helen", "TeeMee", "Xeniel", "Annette", "Sephera", "Rouie", "Krizzix", "Zip", "Mina", "Baldum", "Gildur", "Arum", "Grakk", "Toro", "Ishar", "Aya", "Cresht", "Lumburr", "Omega", "Ming"};
int max_trothu = (int)LENGTH_OF_ARRAY(trothu) - 1;
char heroes[][30] = {"Mina", "Baldum", "Gildur", "Skud", "Arum", "Grakk", "Maloch", "Taara", "Toro", "Ormarr", "Y'bneth", "Xeniel", "Wiro", "Cresht", "Arduin", "Lumburr", "Omega", "Max", "Dextra", "Roxie", "Ata", "Chaugnar", "Thane", "TeeMee", "Alice", "Helen", "Annette", "Sephera", "Rouie", "Krizzix", "Zip", "Ishar", "Aya", "Ming","Butterfly", "Yena", "Veres", "Zanis", "Zuka", "Airi", "Skud", "Amily", "Lu Bu", "Omen", "Florentino", "Taara", "Riktor", "Qi", "Superman", "Astrid", "Volkath","Ryoma", "Errol", "Tachi", "Allain", "Rourke", "Zephys", "Yan", "Wonder Woman", "Arthur", "Kil'Groth", "Bijan", "Liliana", "Nakroth", "Wukong", "Zill", "Zata", "Raz", "Quillen", "Murad", "Paine", "Kriknak", "Aoi", "Enzo", "Sinestrea", "Keera", "Kaine", "The Flash", "Bright", "Veera", "Krixi", "Mganga", "Kahlii", "Diaochan", "Azzen'Ka", "Aleister", "Natalya", "Jinna", "Ilumia", "Preyta", "Raz", "Lauriel", "Ignis", "Tulen", "Marja", "D'arcy", "Dirak", "Zata", "Lorion", "Iggy", "Valhein", "Violet", "Yorn", "Fennik", "Slimz", "Joker", "Tel'Annas", "Moren", "Lindis", "Wisp", "Elsu", "Hayate", "Capheny", "Celica", "Eland'orr", "Laville", "Thorne", "Erin"};
int max_all = (int)LENGTH_OF_ARRAY(heroes) - 1;

void start() {
    interface_vnm();
    random(choice);
}

int interface_vnm() {
    printf("RANDOM TUONG LIEN QUAN / AOV HEROES RANDOM");
    printf("\n----------------------------------------------");
    printf("\nChon vi tri: ");
    printf("\n1. Do don");
    printf("\n2. Dau si");
    printf("\n3. Sat thu");
    printf("\n4. Phap su");
    printf("\n5. Xa thu");
    printf("\n6. Tro thu");
    printf("\n7. Tat ca tuong");
    printf("\n8. Mot so loai tuong");
    printf("\n0. Ket thuc chuong trinh");
    printf("\nLua chon cua ban: ");
    scanf("%d", &choice);
    return choice;
}
int interface_eng() {
    printf("RANDOM TUONG LIEN QUAN / AOV HEROES RANDOM");
    printf("\n----------------------------------------------");
    printf("\nChoose a position: ");
    printf("\n1. Tank");
    printf("\n2. Warrior");
    printf("\n3. Assassin");
    printf("\n4. Mage");
    printf("\n5. Marksman");
    printf("\n6. Support");
    printf("\n7. All heroes");
    printf("\n0. End program");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    return choice;
}
int rand_value(int min, int max){
    return min + (int)( rand() * (max - min + 1.0) / (1.0 + RAND_MAX) );
}
void random(int choice) {
    int max;
    int value;
    switch (choice) {
        case 1: //do don - tank
            value = rand_value(1,max_dodon);
            printf("%s", dodon[value]);
            again();
            break;
        case 2: //dau si - warrior
            value = rand_value(1,max_dausi);
            printf("%s", dausi[value]);
            again();
            break;
        case 3: //sat thu - assassin
            value = rand_value(1,max_satthu);
            printf("%s", satthu[value]);
            again();
            break;
        case 4: //phap su - mage
            value = rand_value(1,max_phapsu);
            printf("%s", phapsu[value]);
            again();
            break;
        case 5: //xa thu - marksman
            value = rand_value(1,max_xathu);
            printf("%s", xathu[value]);
            again();
            break;
        case 6: //tro thu - support
            value = rand_value(1,max_trothu);
            printf("%s", trothu[value]);
            again();
            break;
        case 7: //all
            value = rand_value(1,max_all);
            printf("%s", heroes[value]);
            again();
            break;
        case 8: //multiple
            mix();
            again();
            break;
        case 0:
            printf("\nChuong trinh ket thuc.");
            break;
        default:
            printf("\nGia tri khong ton tai. Hay chon lai!");
            interface_vnm();
            break;
    }
}
void again() {
    printf("\n----------------------------------------------");
    printf("\nBan co muon tiep tuc khong?");
    printf("\n1. Tiep tuc");
    printf("\n2. Dung lai");
    printf("\nLua chon cua ban: ");
    scanf("%d", &again_choice);
    switch (again_choice) {
        case 1:
            system("cls");
            interface_vnm();
            random(choice);
            break;
        case 2:
            printf("Chuong trinh ket thuc.");
            break;
        default:
            printf("Gia tri khong ton tai. Hay chon lai!");
            again();
            break;
    }
}
void mix() {
    printf("\nBan muon chon bao nhieu vi tri? ");
    scanf("%d", &n);   
        switch (n) {
            case 2:
                printf("Vi tri thu nhat: ");
                scanf("%d", &a);
                printf("Vi tri thu hai: ");
                scanf("%d", &b);
                if (a != b) {
                    mix_first(a);
                    mix_second(b);
                    multiple = rand_value(1,2);
                    switch (multiple) {
                        case 1:
                            max_mix = mix_first(a);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", first[multiple]);
                            break;
                        default:
                            max_mix = mix_second(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", second[multiple]);
                            break;
                    }
                }
                else {
                    printf("Gia tri khong phu hop. Hay chon lai!\n");
                    mix();
                }
                break;
            case 3:
                printf("Vi tri thu nhat: ");
                scanf("%d", &a);
                printf("Vi tri thu hai: ");
                scanf("%d", &b);
                printf("Vi tri thu ba: ");
                scanf("%d", &c);
                if (a != b && b != c) {
                    mix_first(a);
                    mix_second(b);
                    mix_third(c);
                    multiple = rand_value(1,3);
                    switch (multiple) {
                        case 1:
                            max_mix = mix_first(a);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", first[multiple]);
                            break;
                        case 2:
                            max_mix = mix_second(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", second[multiple]);
                            break;
                        default:
                            max_mix = mix_third(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", third[multiple]);
                            break;
                    }
                }
                else {
                    printf("\nGia tri khong phu hop. Hay chon lai!");
                    mix();
                }
                break;
            case 4:
                printf("Vi tri thu nhat: ");
                scanf("%d", &a);
                printf("Vi tri thu hai: ");
                scanf("%d", &b);
                printf("Vi tri thu ba: ");
                scanf("%d", &c);
                printf("Vi tri thu tu: ");
                scanf("%d", &d);
                if (a != b && b != c && c != d && d != a) {
                    mix_first(a);
                    mix_second(b);
                    mix_third(c);
                    mix_fourth(d);
                    multiple = rand_value(1,4);
                    switch (multiple) {
                        case 1:
                            max_mix = mix_first(a);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", first[multiple]);
                            break;
                        case 2:
                            max_mix = mix_second(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", second[multiple]);
                            break;
                        case 3:
                            max_mix = mix_third(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", third[multiple]);
                            break;
                        default:
                            max_mix = mix_fourth(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", fourth[multiple]);
                            break;
                    }
                }
                else {
                    printf("\nGia tri khong phu hop. Hay chon lai!");
                    mix();
                }
                break;
            case 5:
                printf("Vi tri thu nhat: ");
                scanf("%d", &a);
                printf("Vi tri thu hai: ");
                scanf("%d", &b);
                printf("Vi tri thu ba: ");
                scanf("%d", &c);
                printf("Vi tri thu tu: ");
                scanf("%d", &d);
                printf("Vi tri thu nam: ");
                scanf("%d", &e);
                if (a != b && b != c && c != d && d != e && e!= a) {
                    mix_first(a);
                    mix_second(b);
                    mix_third(c);
                    mix_fourth(d);
                    multiple = rand_value(1,4);
                    switch (multiple) {
                        case 1:
                            max_mix = mix_first(a);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", first[multiple]);
                            break;
                        case 2:
                            max_mix = mix_second(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", second[multiple]);
                            break;
                        case 3:
                            max_mix = mix_third(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", third[multiple]);
                            break;
                        case 4:
                            max_mix = mix_fourth(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", fourth[multiple]);
                            break;
                        default:
                            max_mix = mix_fifth(b);
                            multiple = rand_value(1,max_mix);
                            printf("\n%s", fifth[multiple]);
                            break;
                    }
                }
                else {
                    printf("\nGia tri khong phu hop. Hay chon lai!");
                    mix();
                }
                break;
            default:
                printf("Gia tri khong ton tai. Hay nhap lai!\n");
                mix();
                break;    
        }
}
int mix_first(int a) {
    switch (a) {
        case 1:
            max_value = max_value + max_dodon;
            a = max_dodon;
            for (int i = 0; i <= max_dodon; i++) {
                strcpy(first[i], dodon[i]);
            }
            break;
        case 2:
            max_value = max_value + max_dausi;
            a = max_dausi;
            for (int i = 0; i <= max_dausi; i++) {
                strcpy(first[i], dausi[i]);
            }
            break;
        case 3:
            max_value = max_value + max_satthu;
            a = max_satthu;
            for (int i = 0; i <= max_satthu; i++) {
                strcpy(first[i], satthu[i]);
            }
            break;
        case 4:
            max_value = max_value + max_phapsu;
            a = max_phapsu;
            for (int i = 0; i <= max_phapsu; i++) {
                strcpy(first[i], phapsu[i]);
            }
            break;
        case 5:
            max_value = max_value + max_xathu;
            a = max_xathu;
            for (int i = 0; i <= max_xathu; i++) {
                strcpy(first[i], xathu[i]);
            }
            break;
        case 6:
            max_value = max_value + max_trothu;
            a = max_trothu;
            for (int i = 0; i <= max_trothu; i++) {
                strcpy(first[i], trothu[i]);
            }
            break;
        default:
            printf("Gia tri khong ton tai. Hay nhap lai!");
            mix();
            break;
        }
    return a;
}
int mix_second(int b) {
    switch (b) {
        case 1:
            max_value = max_value + max_dodon;
            b = max_dodon;
            for (int i = 0; i <= max_dodon; i++) {
                strcpy(second[i], dodon[i]);
            }
            break;
        case 2:
            max_value = max_value + max_dausi;
            b = max_dausi;
            for (int i = 0; i <= max_dausi; i++) {
                strcpy(second[i], dausi[i]);
            }
            break;
        case 3:
            max_value = max_value + max_satthu;
            b = max_satthu;
            for (int i = 0; i <= max_satthu; i++) {
                strcpy(second[i], satthu[i]);
            }
            break;
        case 4:
            max_value = max_value + max_phapsu;
            b = max_phapsu;
            for (int i = 0; i <= max_phapsu; i++) {
                strcpy(second[i], phapsu[i]);
            }
            break;
        case 5:
            max_value = max_value + max_xathu;
            b = max_xathu;
            for (int i = 0; i <= max_xathu; i++) {
                strcpy(second[i], xathu[i]);
            }
            break;
        case 6:
            max_value = max_value + max_trothu;
            b = max_trothu;
            for (int i = 0; i <= max_trothu; i++) {
                strcpy(second[i], trothu[i]);
            }
            break;
        default:
            printf("Gia tri khong ton tai. Hay nhap lai!");
            mix();
            break;
        }
    return b;
}
int mix_third(int b) {
    switch (b) {
        case 1:
            max_value = max_value + max_dodon;
            b = max_dodon;
            for (int i = 0; i <= max_dodon; i++) {
                strcpy(third[i], dodon[i]);
            }
            break;
        case 2:
            max_value = max_value + max_dausi;
            b = max_dausi;
            for (int i = 0; i <= max_dausi; i++) {
                strcpy(third[i], dausi[i]);
            }
            break;
        case 3:
            max_value = max_value + max_satthu;
            b = max_satthu;
            for (int i = 0; i <= max_satthu; i++) {
                strcpy(third[i], satthu[i]);
            }
            break;
        case 4:
            max_value = max_value + max_phapsu;
            b = max_phapsu;
            for (int i = 0; i <= max_phapsu; i++) {
                strcpy(third[i], phapsu[i]);
            }
            break;
        case 5:
            max_value = max_value + max_xathu;
            b = max_xathu;
            for (int i = 0; i <= max_xathu; i++) {
                strcpy(third[i], xathu[i]);
            }
            break;
        case 6:
            max_value = max_value + max_trothu;
            b = max_trothu;
            for (int i = 0; i <= max_trothu; i++) {
                strcpy(third[i], trothu[i]);
            }
            break;
        default:
            printf("Gia tri khong ton tai. Hay nhap lai!");
            mix();
            break;
        }
    return c;
}
int mix_fourth(int b) {
    switch (b) {
        case 1:
            max_value = max_value + max_dodon;
            b = max_dodon;
            for (int i = 0; i <= max_dodon; i++) {
                strcpy(fourth[i], dodon[i]);
            }
            break;
        case 2:
            max_value = max_value + max_dausi;
            b = max_dausi;
            for (int i = 0; i <= max_dausi; i++) {
                strcpy(fourth[i], dausi[i]);
            }
            break;
        case 3:
            max_value = max_value + max_satthu;
            b = max_satthu;
            for (int i = 0; i <= max_satthu; i++) {
                strcpy(fourth[i], satthu[i]);
            }
            break;
        case 4:
            max_value = max_value + max_phapsu;
            b = max_phapsu;
            for (int i = 0; i <= max_phapsu; i++) {
                strcpy(fourth[i], phapsu[i]);
            }
            break;
        case 5:
            max_value = max_value + max_xathu;
            b = max_xathu;
            for (int i = 0; i <= max_xathu; i++) {
                strcpy(fourth[i], xathu[i]);
            }
            break;
        case 6:
            max_value = max_value + max_trothu;
            b = max_trothu;
            for (int i = 0; i <= max_trothu; i++) {
                strcpy(fourth[i], trothu[i]);
            }
            break;
        default:
            printf("Gia tri khong ton tai. Hay nhap lai!");
            mix();
            break;
        }
    return d;
}
int mix_fifth(int b) {
    switch (b) {
        case 1:
            max_value = max_value + max_dodon;
            b = max_dodon;
            for (int i = 0; i <= max_dodon; i++) {
                strcpy(fifth[i], dodon[i]);
            }
            break;
        case 2:
            max_value = max_value + max_dausi;
            b = max_dausi;
            for (int i = 0; i <= max_dausi; i++) {
                strcpy(fifth[i], dausi[i]);
            }
            break;
        case 3:
            max_value = max_value + max_satthu;
            b = max_satthu;
            for (int i = 0; i <= max_satthu; i++) {
                strcpy(fifth[i], satthu[i]);
            }
            break;
        case 4:
            max_value = max_value + max_phapsu;
            b = max_phapsu;
            for (int i = 0; i <= max_phapsu; i++) {
                strcpy(fifth[i], phapsu[i]);
            }
            break;
        case 5:
            max_value = max_value + max_xathu;
            b = max_xathu;
            for (int i = 0; i <= max_xathu; i++) {
                strcpy(fifth[i], xathu[i]);
            }
            break;
        case 6:
            max_value = max_value + max_trothu;
            b = max_trothu;
            for (int i = 0; i <= max_trothu; i++) {
                strcpy(fifth[i], trothu[i]);
            }
            break;
        default:
            printf("Gia tri khong ton tai. Hay nhap lai!");
            mix();
            break;
        }
    return e;
}
int main() {
    srand(time(NULL));
    start();
    
    return 0;
    
}