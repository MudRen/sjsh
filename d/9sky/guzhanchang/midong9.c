// midong5.c

inherit ROOM;

void falldown(object,object);

void create ()
{
  set ("short", "����");
  set ("long", @LONG
������߼�Ϊ΢��������ǿ�ؿ�����������ԼԼ��һЩ������

                       .r""    .F        ^"4.                     
                    .@"        $           .d$b.                  
                  z$b.        J"        .d$$$$$$$c                
                .$$$$$$bc.    $    .e$$$$$$$$$$$$$$c              
               d$$$$$$$$$$$$bdbe$$$$$$$$$$$$$$$$$$$$$.            
              d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$b           
             $$$$$$$$$$$$$$$$     $$$$$$$F*$$$$$$$$$$$$$$          
            $$$$$$$$$$$$$$$$       $$$$$%3   ^"**$$$$$$$$$.        
           d$$$$$$$$$$$$$$$          $$$$$$$$$$$$$$$$$$$$$$b  
LONG);

  set("exits", ([
        "down" : __DIR__"tian9",
      ]));
  set ("sleep_room",1);
  set("objects", ([
        __DIR__"obj/jiangli"  : 1,
      ]));

  setup();
}












