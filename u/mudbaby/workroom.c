#include <ansi.h>

inherit ROOM;

void create ()
{
      set ("short", BLINK HIC"��"+HIY"��"+HIR"��"+HIW"԰"NOR);
set ("long","^O^��߻���һ�����������ǡ��������������������Ը��^O^"+HIW"(wish)\n"
HIC"���"+BLINK HIY"��"NOR+HIC"��"+HIW"��"+HIC"�� ��"+BLINK HIY"��"NOR+HIC"������"+BLINK HIY"��"NOR+HIC"���� ��������㡤�����
"+HIW"��"+HIC" �������� "+HIW"��"+HIC"���������㣮"+HIW"��"+HIC"��"+BLINK HIY"��"NOR+HIC"����"+HIW"��"+HIC" ������
��� "NOR+BLINK HIR"�����Ǽ����� "NOR+HIW"��"+HIC"�� ����"+BLINK HIY"��"NOR+HIC"���㣮���"+HIW"��"+HIC"�� ����
��㣮��"+BLINK HIY"��"NOR+HIC" �������㣮���㣮"+BLINK HIY"��"NOR+HIW"��"+HIC"�� ������㣮��
�㣮��� ��"+BLINK HIY"��"NOR+HIC"��"+BLINK HIG"��ҲҪ׷����"NOR+HIC"  �㣮��㣮"+BLINK HIY"��"NOR+HIC"��"+HIW"��"+HIC"�㣮
�������"+BLINK HIY"��"NOR+HIC"�㣮���㣮"+HIW"��"+HIC"�� �������㣮"+HIW"��"+HIC"�� ������
"+HIW"��"+HIC"�������㣮�ࡤ���"+BLINK HIB"����Զ����"NOR+HIC"��"+HIW"��"+HIC"�㣮����
�������"+BLINK HIY"��"NOR+HIC"�㣮����"+BLINK HIY"��"NOR+GRN"���� ������"NOR+HIC"��㣮"NOR+HIW"��"+HIC"�� ����"NOR+GRN"
������������������������  ������������
����������  "+WHT"/��\\ �� ���� "+GRN"��������������"+YEL"����������������������
 ���������� "+WHT"/��\\/��\\��"+GRN" ��������������"+YEL"����"+BLINK HIC"������"NOR+HIY"��"+HIW"¶�칤����"NOR+YEL"��
 �T�n�T�n�T "+WHT" <|  || "+YEL"�T�n�T�n�T�n�T�n�T ���Щ��������������Щ�
"NOR);

        set("exits", 
        ([ //sizeof() == 2
              "ws" : "/d/wiz/wizroom",
                "kz" : "/d/city/kezhan",
              "tj" : "/d/guzhanchang/sky",
          "ljg":"/d/xueshan/lingjiu",
       "ydn":"/d/12gong/palace",
        "down"   : "/u/mudbaby/room/liangong",
       "li" : "/d/dntg/yunlou/yunloutai",
]));
set("valid_startroom", 1);
        set("no_fight",1);
        set("no_time",1);
      set("objects", ([
//   "/u/mudbaby/obj/dan": 1,
//      "/obj/wiz/rack" : 1,
//     "/u/mudbaby/npc/dog": 1,
//   "/u/mudbaby/npc/chunjiedashi": 1,
//     "/d/xueshan/npc/shizhe": 1,
     ]));
        setup();
//   call_other( "/obj/board/baby_b","???");
}
void init()
{
      add_action("do_wish","wish");
}
int do_wish()
{
object me;
me = this_player();
     if( time() - me->query("wish/time_start") <77)
     return notify_fail("����ô��ô̰�ģ�Ը��̫�����ʵ�ֲ��˵�Ŷ����\n"); 
message("channel:chat",HIC"�����γ��桿"+HIW"��˵"HIG+me->query("name")+HIW"��"+BLINK HIC"��"+HIY"��"+HIR"��"+HIW"԰"NOR+HIW"��������������������һ�����õ���Ը��\n"
+HIC"                        ���ף���������γ���!\n"NOR,users());
      me->set("wish/time_start", time());
 return notify_fail(HIY"\n���������������������һ�����õ���Ը��ףԸ���������γ���!\n"NOR);
}

