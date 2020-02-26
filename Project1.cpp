//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 AnsiString strMessage = "Witaj w grze PingPong.\n\n"+
                        "Lewy gracz steruje wciskaj�c klawisze A oraz Z.\n"+
                        "Prawy gracz steruje wciskaj�c strza�ki do g�ry i w d�.\n"+
                        "\nDla urozmaicenia zabawy:\n"+
                        "Odbicie pi�eczki zmienia k�t w zale�no�ci od miejsca odbicia\n"+
                        "Co 5 odbi� pi�eczka przyspiesza, a� do osi�gni�cia maksymalnej pr�dko�ci\n\n"+
                        "Mi�ej zabawy!";
                 ShowMessage(strMessage);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
