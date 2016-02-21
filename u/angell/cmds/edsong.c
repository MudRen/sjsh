// Cmds:/cmds/wiz/edsong.c
// Written by jjgod@FYTX.

#include <ansi.h>
inherit F_CLEAN_UP;
string replace_color(string arg,int flag);
int main(object me, string arg)
{
mapping song;
string newsong;
string *editid;
editid=({"buwawa","lovemy","ferser","yingying","lianer","xflower","cartone","trhy","xhuowu","hawks"});
if(!wizardp(me)&&member_array(me->query("id"), editid) ==-1)
return notify_fail("ֻ����ʦ����������ʿ�����ʸ���ʣ�\n");
if( !arg ) return notify_fail("��Ҫ�༭ʲô������\n");

if( sscanf(arg, "-c %s %s", arg, newsong) ) {
        if(!wizardp(me)) return notify_fail("��ֻ��������ף�\n");
write("����������" + arg + "\n");
MUSIC_D->set_song(newsong, MUSIC_D->query_song(arg));
return 1;
}

if( sscanf(arg, "-d %s", arg) ) {
        if(!wizardp(me)) return notify_fail("��ֻ��������ף�\n");
write("ɾ��������" + arg + "\n");
MUSIC_D->delete_song(arg);
return 1;
}

if( sscanf(arg, "-p %s", arg) ) {
song = MUSIC_D->query_song(arg);
printf("\n���ߣ�%-10s\n��Ŀ��%s\n",song["author"],song["name"]);
printf("���ݣ�\n%s\n",song["song"]);
return 1;
}
song=([]);
write("������������ߣ�");
input_to("get_author",me,arg,song);
return 1;
}

void get_author(string author,object me,string id,mapping song)
{
if (author==""||author==".") {
song["author"]="������";
}
else {
song["author"]=author;
}
write("�����������Ŀ��");
input_to("get_name",me,id,song);
return;
}

void get_name(string name,object me,string id,mapping song)
{
if (name==""||name==".") {
song["name"]="����";
}
else {
song["name"]=name;
}
write("������������ݣ�\n");
me->edit((: call_other, __FILE__, "get_context", me,id,song:));
return;
}

void get_context(object me,string id,mapping song,string context)
{
if (context==""||context==".") {
song["song"]="��Ҳ��֪��������Щʲôѽ��";
}
else {
song["song"]=context;
}
write("��������Ĳ��õ���ɫ�������ж�����á�,���ָ�����");
input_to("get_color",me,id,song);
return;
}

void get_color(string color,object me,string id,mapping song)
{
string *colors;

if (color==""||color==".") {
// Ĭ�ϵ���ɫ
song["color"]=({CYN,WHT});
}
else {
color=replace_color(color,1);
color=replace_string(color,NOR,"");
colors=explode(color,",");
song["color"]=colors;
}
MUSIC_D->set_song(id, song);
write("������ "HIW+id+NOR" �༭��ϡ�\n");
return;
}
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
write(@HELP
ָ���ʽ��edsong [-c|-d|-p] <song>
 
���ָ������޸ģ�ɾ���������г������ݡ����� -d ������ɾ��
ָ���������� -p ��������г�ָ�����������ݡ��г���˳�����
������ʱ��ͬ��
 
һ������ѶϢ�����кܶ��У��ڿհ�������'.' �����������������

HELP
    );
    return 1;
}
