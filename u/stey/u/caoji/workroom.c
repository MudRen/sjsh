// Room: /u/guoth/workroom.c
inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIR "�˴������׳�" NOR);
         set ("long", @LONG

��������վ����Ϸ���ӿ���������Ŀ������Ĵ����ҷ������㣬���ȱ�
�ȡ����������Կ����ù���һ���Ա��Ӷ����������ϣ������м�����ʢ����
��ͷ����̨���˻��䣬��¶�Ÿ����㲽���ĵĵ��Կ�������ع����š�����
��������Beyond�ĸ�--����ء���������ǽ���ϻ�����һ��zmud�ĵ�ͼ
(Maps),��ϸ����ȥ��ͼ�ϱߺ���д��һ��ʫ(shi)��
LONG);

            set("exits", ([
                    "kezhan" :  "/d/city/kezhan",
                    "wizroom" :  "/d/wiz/wizroom",
                    "system" :  "/d/wiz/system",
                    "guest" :  "/d/wiz/guest",
                      "up" :  "/u/caoji/sleeproom",
                      "center" :  "/u/city/center",
                     ]));   

            set("item_desc", ([
                "Maps" : HIB "\n��ʶ��������꣬���´;ƽ���Ե,�����������˶����̽�����Ϊ���ա�\n" NOR,
                "shi" : BLINK HIW "\n����Ϸ���� ��� 2000.10.27\n" NOR,
           ]));

       set("no_fight",1);
       set("valid_startroom", 1);

        set("no_clean_up", 0);
       setup();
        replace_program(ROOM);

}
