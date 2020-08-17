using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

        }
        public static void CurrentQuestion(string correctAnswer)
        {

            do
            {
                Console.WriteLine("Please enter answer: ");
                string userAnswer = Console.ReadLine();

                if ((userAnswer != "A") && (userAnswer != "B") && (userAnswer != "C"))
                {
                    Console.WriteLine("\nError - Not a Valid Input");
                }
                else
                {
                    if (userAnswer == correctAnswer)
                    {
                        Console.WriteLine("\nThat is correct!");
                        break;
                    }
                    else if (userAnswer != correctAnswer)
                    {
                        Console.WriteLine("\nSorry, that is incorrect");
                        break;
                    }
                }
            } while (true);
        }

    }
}

