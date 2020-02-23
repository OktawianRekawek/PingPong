//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *Ball;
        TTimer *BallTimer;
        TImage *RightPaddle;
        TTimer *RightPaddleUp;
        TTimer *RightPaddleDown;
        TImage *LeftPaddle;
        TTimer *LeftPaddleUp;
        TTimer *LeftPaddleDown;
        TLabel *Scores;
        TButton *NextRound;
        void __fastcall BallTimerTimer(TObject *Sender);
        void __fastcall RightPaddleDownTimer(TObject *Sender);
        void __fastcall RightPaddleUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LeftPaddleUpTimer(TObject *Sender);
        void __fastcall LeftPaddleDownTimer(TObject *Sender);
        void __fastcall NextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
