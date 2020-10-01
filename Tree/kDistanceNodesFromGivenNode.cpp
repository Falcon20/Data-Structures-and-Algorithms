//might find it lengthy :P but for understanding start from "printkdistanceNode" function, Question is: print number of nodes k distance from given node

vector<int> v;
int cur=0;
bool flag=0;
deque<node* >dq;
void print(vector<int> &v){
    if(v.empty()) cout<<"-1"<<endl;
    else{
        // sort(v.begin(),v.end());
        for(auto u:v) cout<<u<<" ";
        v.clear();
    }    
}
void printkdistanceNodeDown(node *root, int k)
{
    if(root==NULL) return;
    if(k==0){
        v.push_back(root->data);
        return;
    }
    printkdistanceNodeDown(root->left,k-1);
    printkdistanceNodeDown(root->right,k-1);
}

bool check(node* root, node* target){
    if(root==NULL) return 0;
    if(root->data==target->data||flag){
        flag = 1;
        return 1;
    }
    dq.push_back(root);
    bool l = check(root->left,target);
    bool r = check(root->right,target);
    if(!flag) dq.pop_back();
    return l||r;
}

void traverse(node* root, int k){
    if(!root) return;
    if(k==0){
        v.push_back(root->data);
        return;
    }
    traverse(root->left,k-1);
    traverse(root->right,k-1);
}

int printkdistanceNode(node* root, node* target , int k)
{
    flag = 0;
    cur = 0;
    dq.clear();
    if(root->data==target->data){
        printkdistanceNodeDown(root,k);
        print(v);
    }
    else{
        if(check(root,target)){
            // for(auto u:dq){
            //     cout<<u->data<<endl;
            // }
            int n = dq.size();
            int count=0;
            printkdistanceNodeDown(target,k);
            if(k==1){
                v.push_back(dq[n-1]->data);
            }
            else{
                for(auto i=n-1; i>=0; i--){
                    count++;
                    if(k-count>=0){
                    if(i==0&&k-count==0) v.push_back(dq[i]->data);    
                    else if(i==n-1&&dq[i]->left->data==target->data)
                        traverse(dq[i]->right,k-count-1);
                    else if(i==n-1&&dq[i]->right->data==target->data)
                        traverse(dq[i]->left,k-count-1);
                    else if(dq[i]->right->data==dq[i+1]->data)
                        traverse(dq[i]->left,k-count-1);
                    else if(dq[i]->left->data==dq[i+1]->data)
                        traverse(dq[i]->right,k-count-1);
                    }    
                }
            }    
            print(v);
        }
        else return -1;
    }
}
