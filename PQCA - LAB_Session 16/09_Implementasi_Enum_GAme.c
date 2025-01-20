#include <stdio.h>

// Definisi enum untuk tipe senjata
typedef enum {
    SWORD,
    BOW
} WeaponType;

// Definisi struct untuk senjata
typedef struct {
    char name[20];
    int damage;
} Sword;

typedef struct {
    char name[20];
    int damage;
    int range;
} Bow;

typedef union {
    Sword sword;
    Bow bow;
} Weapon;

typedef struct {
    char playerName[20];
    Weapon weapon;
    WeaponType weaponType; // Menggunakan enum untuk tipe senjata
} Player;

int main() {
    Player player1;

    // Input player name
    printf("Enter player name: ");
    fgets(player1.playerName, sizeof(player1.playerName), stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = '\0'; // remove newline character

    // Choose weapon type
    printf("Choose weapon type (0 for Sword, 1 for Bow): ");
    scanf("%d", (int*)&player1.weaponType);

    if (player1.weaponType == SWORD) {
        // Input sword details
        printf("Enter sword name: ");
        scanf("%s", player1.weapon.sword.name);
        printf("Enter sword damage: ");
        scanf("%d", &player1.weapon.sword.damage);
    } else if (player1.weaponType == BOW) {
        // Input bow details
        printf("Enter bow name: ");
        scanf("%s", player1.weapon.bow.name);
        printf("Enter bow damage: ");
        scanf("%d", &player1.weapon.bow.damage);
        printf("Enter bow range: ");
        scanf("%d", &player1.weapon.bow.range);
    } else {
        printf("Invalid weapon type\n");
        return 1;
    }

    // Output player and weapon details
    printf("\nPlayer Name: %s\n", player1.playerName);
    if (player1.weaponType == SWORD) {
        printf("Weapon Type: Sword\n");
        printf("Sword Name: %s\n", player1.weapon.sword.name);
        printf("Sword Damage: %d\n", player1.weapon.sword.damage);
    } else {
        printf("Weapon Type: Bow\n");
        printf("Bow Name: %s\n", player1.weapon.bow.name);
        printf("Bow Damage: %d\n", player1.weapon.bow.damage);
        printf("Bow Range: %d\n", player1.weapon.bow.range);
    }

    return 0;
}