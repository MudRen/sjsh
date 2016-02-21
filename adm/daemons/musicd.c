// Daemon:/adm/daemons/musicd.c
// ���ָ����������


#include <ansi.h>

inherit F_SAVE;
#define MUSIC_FILE "/data/music.o"

/*************************************
 * ��ʽΪ��
 * string��������:([   "name":string��������,
 * "song":string*��������,
 * "author":string��������
 *  "color":string*������ɫ,]),
 *
 ************************************/

mapping songs=([
"yumeiren":([
"name":"������",
"song":"
�������º�ʱ�ˣ�
����֪���٣�
С¥��ҹ�ֶ��磬
�ʹ��������������С�

��������Ӧ���ڣ�
ֻ�����ոġ�
�ʾ����м���
ǡ��һ����ˮ������",
"author":"����",
"color":({HIC,HIY}),
]),
"xiangjianhuan_i":([
"name":"����� I",
"song":"
�ֻ�л�˴��죬̫�Ҵҡ�
�ļ����������������磡

��֬�ᣬ��������ʱ�أ�
������������ˮ������",
"author":"����",
"color":({HIG,HIM}),
]),
"xiangjianhuan_ii":([
"name":"����� II",
"song":"
���Զ�����¥�����繳��
��į��ͩ��Ժ�����

�����ϣ����ң�����
����һ����ζ����ͷ��",
"author":"����",
"color":({HIB,HIR}),
]),

]);

void create()
{
seteuid(getuid());

if (file_size(MUSIC_FILE)<=0){
save();
}
restore();
}

string query_save_file()
{
return MUSIC_FILE;
}

// ������һЩ��ѯ�ĺ���
mapping query_songs()
{
return songs;
}

mapping query_song(string id)
{
return songs[id];
}

string query_song_name(string id)
{
return songs[id]["name"];
}

string *query_song_color(string id)
{
return songs[id]["color"];
}

string query_song_context(string id)
{
return songs[id]["song"];
}

string query_song_author(string id)
{
return songs[id]["author"];
}

// ������һЩ�޸ĵĺ���
void set_song(string id,mapping song)
{
songs[id]=song;
log_file("music",sprintf("%s �����뵽�������С�\n",id));
save();
}

void delete_song(string id)
{
map_delete(songs,id);
log_file("music",sprintf("%s ������������ɾ����\n",id));
save();
}
