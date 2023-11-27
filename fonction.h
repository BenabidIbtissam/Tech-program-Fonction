#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//Déclarations des fonctions :




//la fonction f(x)

double fonction_F(double x){

   double Expression = (((2*pow(x,3)) + 3 ) * (pow(x,2)-1) )/sqrt(3*(pow(x,2)) + 1);

    return Expression ;
}

//Calcul d'approximation du f'

double fonction_Derive(double x , double h){

    double Expression = (fonction_F(h + x) - fonction_F(h - x)) / (2 * h);

    return Expression ;
}


//Calcul d'approximation du f''

double fonction_der_Sec(double x , double h){

    double Expression = (fonction_F(x + h) - 2 * fonction_F(x) + fonction_F(x - h)) / (h * h);
    return Expression ;
}


//determination du signe de la focntion 


char signe_Fonction(double x , double h){

      double resultat = fonction_der_Sec( x ,  h);

     if(resultat > 0){
         printf("+");
        
      } else if (resultat < 0){
         printf("-");
      }else {
         printf("0");} 
        
     
      }



double  lire_valeur_x(){

    double x;

    printf("Entrez x :  ");
    scanf("%lf", &x);
  

    return x  ;

}


double  lire_valeur_h(){

    double h;

     printf("Entrez h :  ");
    scanf("%lf", &h);

    return  h ;

}


void afficher_resultat() {
    printf("Calcul par f           -----------> 1 \n");
    printf("Calcul par f'          -----------> 2 \n");
    printf("Calcul par f''         -----------> 3 \n");
    printf("Calcul du signe de f'' -----------> 4 \n");
    printf("Quitter                -----------> 5 \n");
    int choix;
    scanf("%d", &choix);

double x , h;

    switch (choix) {
        case 1:
             x = lire_valeur_x();
            printf("f(%.2lf) = %.6f\n", x, fonction_F(x));
            break;
           // afficher_resultat();
        case 2:
        x = lire_valeur_x();
        h = lire_valeur_h();
            printf("f'(%0.2lf) = %.6f\n", x, fonction_Derive(x, h));
            break;
        case 3:
        x = lire_valeur_x();
        h = lire_valeur_h();
            printf("f''(%0.2lf) = %.6f\n", x, fonction_der_Sec(x, h));
            break;
        case 4:
         x = lire_valeur_x();
         h = lire_valeur_h();
            printf("Le signe de f''(%.2lf) est : %c\n", x, signe_Fonction(x, h));
            break;
        case 5:
            break; 
        default:
            printf("Option invalide.\n");
    }
}