#include <ansi.h>
inherit ROOM; 
void close_path(); 
void create()
{
set("short",HIC"��԰"NOR);
set("long",

"����һ�����󵫴������µĻ�԰,԰���ֵ�ȫ��ӣ������\n" 
"�ƺ�������Ǵ��������µ�����,����������ӣ��ʢ�� \n" 
"��,��ʱ�м���ۺ�ɫ�Ļ���(flower)������,����Ĵ�\n " 
"���������,�ټ���������Ƣ�����еı���֮���Ļ���,\n" 
"���Ȼ��ȴ��һ�з���,���������ڴ��ˡ�\n" 
"԰�е�һ��ʯͷ�Ͽ��ż�����:\n"
                  " "HIG" *************\n"NOR 
                     " "HIG"*"NOR+BLINK+HIR" ��"HIY" ��"HIC" ͬ"HIB" �� "NOR+HIG"*\n"NOR
                  " "HIG" *************\n"NOR 
); 

set("exits", ([ 
"down":"/d/city/kezhan", 
"go":"/d/wiz/wizroom",
"north":"/d/wiz/system", ])); 

set("item_desc", ([ 
"stone": HIG"�������ֵ�ʯͷ�ƺ������ƶ�(move)��\n"NOR, 
"flower" : MAG "ϣ����ϲ�����ӣ��\n" NOR, ])); 

setup(); 

}

void init() 
{ 
add_action("do_move", "move"); 
} 

void close_path() 
{ 
if( !query("exits/enter") ) return;
message("vision", HIW"��ʯ�����¹�λ����ס��������ڡ�\n"NOR,this_object() ); 
delete("exits/enter"); 
} 

int do_move(string arg)
{
object me; 
me = this_player(); 
if( !arg || arg=="" ) return 0; 

if( arg=="stone" ) 
{ 
write(HIC"�������ƶ���ʯ��,\n"NOR);
if( (string) me->name() == "��ʹ֮��" )
{
write(HIY"���������һ����ڡ�\n"NOR);
if( !query("exits/west") ) { 
set("exits/enter", __DIR__"workroom");
call_out("close_path", 3);
}
return 1; 
} 
else 
{ write(HIY"��ʯ����˿������\n"NOR); 
message_vision( HIR "ͻȻʯ����ӿ��һ���ϻ�ɫ������$N���ɵ�������һ������\n\n\n" NOR,me);
if(!me->query_condition("moon_poison")) me->apply_condition("moon_poison",random(10)+10);
} 
return 1;
} 
write("��Ҫ�ƶ�ʲô��\n"); 
} 

