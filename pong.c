int scrin_height = 27;    // высота поля
int scrin_longhest = 82;  //длина поля
int score_height = 2;     // высота табло
int score_longest = 82;   // длина табло
int racketY_P1 = 12;      //начальное положение левой ракетки по оси У
int racketY_P2 = 12;      // начальное положение правой ракетки по оси У
int racketX_P1 = 1;       // начальное положение левой ракетки по оси Х
int racketX_P2 = 80;      // начальное положение правой ракетки по оси Х
int rackP1 = 0;           // изменение положения левой ракетки
int rackP2 = 0;           // изменение положения правой ракетки
int ball_S_X = 40;        // начальное положение мяча по оси Х
int ball_S_Y = 13;        // начальное положение мяча по оси У
int ball_X = 0;           // изменение положения мяча по оси Х
int ball_Y = 0;           // изменение положения мяча по оси У
int vector_X = 1;         // направление движения мяча по оси Х
int vector_Y = 1;         // направление движения мяча по оси У
int GO = 1;               // переменная для запуска цикла
int winscore = 21;        // максимальное значение очков победителя
int scoreL = 0;           // начальное значение очков левого игрока
int scoreR = 0;           // начальное значение очков левого игрока

void tablo();
void racket_move();
void clear_screen(void);
void screen_ren();
void ball_move();
// главная функция, которая запускает процесс
int main() {
    rackP1 = racketY_P1;
    rackP2 = racketY_P2;
    ball_X = ball_S_X;
    ball_Y = ball_S_Y;
    printf("Чтобы начать игру введите S: ");
    char s;
    s = getchar();
    if (s == 'S') {
        while (GO) {
            racket_move();
            clear_screen();
            ball_move();
            tablo();
            screen_ren();
            if (scoreL == winscore) {
                printf("CONGRATULATION!!! PLAYER ONE IS WON!");
                break;
            }
            if (scoreR == winscore) {
                printf("CONGRATULATION!!! PLAYER TWO IS WON!");
                break;
            }
        }
    } else {
        return 1;
    }

    return 0;
}
// функция отрисовки экрана (табло и поле)
void screen_ren() {
    for (int y = 0; y < score_height; y++) {
        for (int x = 0; x < score_longest; x++) {
            if ((y == 0)) {
                printf("*");
            } else if (x == 38 && y == 1) {
                printf("%d    %d", scoreL, scoreR);
            } else if (x < scrin_longhest - 7) {
                printf(" ");
            }
        }

        printf("\n");
    }
    for (int y = 0; y < scrin_height; y++) {
        for (int x = 0; x < scrin_longhest; x++) {
            if ((x == racketX_P1 && (y == rackP1 - 1 || y == rackP1 + 1 || y == rackP1)) ||
                (x == racketX_P2 && (y == rackP2 - 1 || y == rackP2 + 1 || y == rackP2))) {
                printf("|");
            } else if (x == ball_X && y == ball_Y) {
                printf("o");
            } else if ((y == 0) || (y == scrin_height - 1)) {
                printf("*");
            } else if ((x == 0) || (x == scrin_longhest - 1) || (x == scrin_longhest / 2)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
// функция переноса поля в верх терминала
void clear_screen(void) { printf("\33[0d\33[2J"); }
// функция движения ракетки
void racket_move() {
    char temp;
    temp = getchar();
    if (temp == 'a') {
        if ((rackP1 - 2) != 0) {
            rackP1 -= 1;
        }
    }
    if (temp == 'z') {
        if ((rackP1 + 2) != scrin_height - 1) {
            rackP1 += 1;
        }
    }
    if (temp == 'k') {
        if ((rackP2 - 2) != 0) {
            rackP2 -= 1;
        }
    }
    if (temp == 'm') {
        if ((rackP2 + 2) != scrin_height - 1) {
            rackP2 += 1;
        }
    }
}
// функция движения мяча
void ball_move() {
    if (ball_Y == 1 || ball_Y == scrin_height - 2) {
        vector_Y = -(vector_Y);
    }
    if (ball_X == racketX_P1 + 1 && (ball_Y == rackP1 || ball_Y == rackP1 + 1 || ball_Y == rackP1 - 1)) {
        vector_X = -(vector_X);
    }
    if (ball_X == racketX_P2 - 1 && (ball_Y == rackP2 || ball_Y == rackP2 + 1 || ball_Y == rackP2 - 1)) {
        vector_X = -(vector_X);
    }

    ball_X += vector_X;
    ball_Y += vector_Y;
}
// функция счетчика очков
void tablo() {
    if (ball_X < 2) {
        scoreR++;
        ball_X = ball_S_X;
        ball_Y = ball_S_Y;
        vector_X = -(vector_X);
        vector_Y = -(vector_Y);
    }

    if (ball_X > 79) {
        scoreL++;
        ball_X = ball_S_X;
        ball_Y = ball_S_Y;
        vector_X = -(vector_X);
        vector_Y = -(vector_Y);
    }
}
