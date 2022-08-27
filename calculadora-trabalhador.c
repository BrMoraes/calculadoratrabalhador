/* 
Programa que calcula o valor que o trabalhador tem direito a receber semanalmente. 
Leva em consideração as horas extras (50% adicional por hora acima de 40h/semana) 
e feriados(100% adicional por hora trabalhada no dia). 

Criado por: Bruno Travassos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   int horas;
   int horas_extras;
   int horas_feriado;
   float valor_hora;
   float salario_semanal;
   float dias_trabalhados_feriado;
   char trabalhou_feriado;

   printf("Trabalhou em feriado essa semana?\n Se sim, digite S. Se nao, digite N:");
   scanf("%s", &trabalhou_feriado);

   if (trabalhou_feriado == 'S' || trabalhou_feriado == 's')
   {
      printf("Digite o numero de horas trabalhadas durante a semana(SEM contar o feriado):\n");
      scanf("%d", &horas);

      printf("Digite o numero de horas trabalhadas NO FERIADO desta semana:\n");
      scanf("%d", &horas_feriado);
   }
   else if (trabalhou_feriado == 'N' || trabalhou_feriado == 'n')
   {
      printf("Digite o numero de horas trabalhadas durante a semana:\n");
      scanf("%d", &horas);
   }

   printf("Digite o valor recebido por hora trabalhada(Ex: 13.50):\n");
   scanf("%f", &valor_hora);

   switch (trabalhou_feriado)
   {
   case 'S':
   case 's':
      if (horas <= 40)
      {
         salario_semanal = (horas * valor_hora) + (horas_feriado * (valor_hora * 2));
         printf("Seu salario semanal foi de %f", salario_semanal);
      }
      else if (horas > 40 && horas <= 44)
      {
         salario_semanal = ((40 * valor_hora) + ((horas - 40) * (valor_hora * 1.5))) + (horas_feriado * (valor_hora * 2));
         printf("Seu salario semanal foi de %f", salario_semanal);
      }
      break;
   case 'N':
   case 'n':
      if (horas <= 40)
      {
         salario_semanal = horas * valor_hora;
         printf("Seu salario semanal foi de %f", salario_semanal);
      }
      else if (horas > 40 && horas <= 44)
      {
         salario_semanal = ((40 * valor_hora) + ((horas - 40) * (valor_hora * 1.5)));
         printf("Seu salario semanal foi de %f", salario_semanal);
      }
      break;
   }
}