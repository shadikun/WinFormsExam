using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Question
    {
        String question;

        string[] answer = null;

        int True;
    }
}
int score = 0;
int i = -1;
int a = 0;

string[] questions = new string[] {
    "q1",
    "q2",
    "q3",
    "q4" };

string[] answers = new string[] {
"9", "81", "729", "2", "4", "2",
"9", "1", "zebra", "aardvark",
"fish", "gnu", "31",
"81", "91", "88" };

private void btnStart_Click(object sender, EventArgs e)
{
    if (i < questions.Length)
        i++;
    //txtScore.Text = score;

    lblQuestion.Text = questions[i];

    radA.Text = answers[a];
    a++;
    radB.Text = answers[a];
    a++;
    radC.Text = answers[a];
    a++;
    radD.Text = answers[a];
    a++;

    btnStart.Visible = false;
    btnStart.Enabled = false;
    btnSubmit.Visible = true;
    btnSubmit.Enabled = true;

}

private void btnSubmit_Click(object sender, EventArgs e)
{
    {
        if (i == 0 && radB.Checked)
        {
            MessageBox.Show("Correct");
            score++;
            txtScore.Text = Convert.ToString(score);
            btnSubmit.Enabled = false;
            btnSubmit.Visible = false;
            btnStart.Visible = true;
            btnStart.Enabled = true;
            btnStart.Text = "Next";
        }

        else
        {
            MessageBox.Show("Incorrect");
            score--;
        }