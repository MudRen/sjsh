// ������

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ǵ��³ǵĳ���֮��-������-,�����±���-����-��
���õ�ǽ��д��:
                   ********************
                   ****��***��***��****
                   ********************
LONG);

        set("exits", 
        ([ //sizeof() == 4
        ]));

        set("objects", 
        ([ //sizeof() == 1
         "/d/milin/npc/diyu" : 1,
        ]));

        set("no_quit", 1);
        setup();
}

void init()
{
        add_action("do_wa", "wa");
}

int do_wa()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/
message_vision(HIY "$Nʹ�����ڰ���,�۵���ͷ�Ǻ�����Ȼֻ��$N���һ���ڹ�,֮��Ͳ�������Ӱ��\n" NOR, me);
        me->move("/d/milin/qy/sc");
        message_vision(HIY "ֻ��$N�������,�Ǳ��ĵ���������\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}
