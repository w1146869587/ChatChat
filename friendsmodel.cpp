#include "friendsmodel.h"
#include<QDebug>
FriendsModel::FriendsModel(QObject* parent):QAbstractListModel(parent)
{

}

void FriendsModel::pushBack(QString ipv4, QString nickName)
{
    beginInsertColumns(QModelIndex(),rowCount(),rowCount());
    FriendItem item=FriendItem(ipv4,nickName);
    items.push_back(item);
    endInsertRows();
}

void FriendsModel::clear()
{
    beginRemoveRows(QModelIndex(),0,items.size());
    items.clear();
    endRemoveRows();
}



int FriendsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->items.size();
}

QVariant FriendsModel::data(const QModelIndex &index, int role) const
{
    int row=index.row();
    if(row<0||row>items.size()){
        return QVariant();
    }
    FriendItem item=items[row];
    if(role==Role::role1){
        return item.getIpv4();
    }
    else if(role==Role::role2){
        return item.getNickName();
    }
//    else if(role==Role::role3){
//        //when use "chatRecordsModel" in qml, it's neccessary to judge if the pointer has been initialized
//        if(item.getChatRecordsModel()==NULL){
//            item.setChatRecordsModel(new ChatRecordsModel);
//            return item.getChatRecordsModel();
//        }
//        else{
//            return item.getChatRecordsModel();
//        }
//    }
    return QVariant();
}

QHash<int, QByteArray> FriendsModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[Role::role1]="ipv4";
    hash[Role::role2]="nickName";
//    hash[Role::role3]="chatRecordsModel";
    return hash;
}

QString FriendItem::getIpv4() const
{
    return ipv4;
}

QString FriendItem::getNickName() const
{
    return nickName;
}

//ChatRecordsModel *FriendItem::getChatRecordsModel() const
//{
//    return chatRecordsModel;
//}

//void FriendItem::setChatRecordsModel(ChatRecordsModel *value)
//{
//    chatRecordsModel = value;
//}