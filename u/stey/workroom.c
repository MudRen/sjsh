// Room: /d/wiz/punish.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"�𱦱��Ŀ������"NOR);
        set("long", HIC@LONG
         *�������*
               /-----\                                         
              /       \                                             ^
         +   /=========\        +      �� ��  ��                   +
     +        |O  _  O|           ��   ��  ��  ��   ����               
         +    |   H   |       �� +��  �� ��      ��              
           ~~~~~~~~~~~~~~~   ..  ��  ..  ��..  ������..   ��   
         ��  ��           ��                                  
       �� �� ������  �� ��  �� 
�𱦱��Ŀ������Ư���ڰ�ɫ��ãã�ƺ�֮�ϣ�һ��ǧ��                                                 
LONG NOR );

  set("chat_room",1);
        set("valid_startroom", 1);
                set("exits", 
        ([ //sizeof() == 4
                "kz" :   "/d/city/kezhan",
                "jail":  "/d/wiz/punish",
                "wiz" :  "/d/wiz/wizroom",
                "wdd" :  "/d/qujing/wudidong/kitchen",
                "guest" :"/d/wiz/guest",
        ]));
        set("objects", ([ /* sizeof() == 1 */
                "/d/ourhome/npc/bigeye" : 1,
        ]));


        setup();

}
void init()
{   
        if (!wizardp(this_player())) 
             add_action("block_cmd","",1);      
        else
             add_action("read_book","read");
}

int block_cmd()
{
        string verb = query_verb();

        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="chat") return 0;//allow chat
        if (verb=="rumor") return 0;//allow rumor
//        if (verb=="quit") return 0;
        if (verb=="look") return 0;
        return 1;
}
int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�ظ��ʲ\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="death" && arg!="call" && arg!="mon" ) return 0;
   if (arg=="death") {
                if(file_size("/log/death")>0)
                this_player()->start_more( read_file("/log/death"));
        }
   if (arg=="call") {
                if(file_size("/log/static/call_player")>0)
                this_player()->start_more( read_file("/log/static/call_player"));
        }
   if (arg=="mon") {
                if(file_size("/log/monitord")>0)
                this_player()->start_more( read_file("/log/monitord"));
        }       
   write("\n");   
      return 1;
}
