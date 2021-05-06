//	两数之和（使用链表进行计算）

//	链表结构定义
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//	solution方法
//	该方法会复用后面的
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1, *p2 = l2;
		ListNode* head = new ListNode();
		ListNode* result = head;
		ListNode* pre = head;
		while (p1 && p2)
		{
			result->val = p1->val + p2->val + result->val;
			ListNode* next = new ListNode();
			if (result->val >= 10)
			{
				next->val = result->val / 10;
				result->val %= 10;
			}
			result->next = next;
			pre = result;
			result = next;
			p1 = p1->next; p2 = p2->next;
		}
// 		if (p1)
// 		{
// 			while (p1)
// 			{
// 				result->val = p1->val + result->val;
// 				ListNode* next = new ListNode();
// 				if (result->val >= 10)
// 				{
// 					next->val = result->val / 10;
// 					result->val %= 10;
// 				}
// 				result->next = next;
// 				pre = result;
// 				result = next;
// 				p1 = p1->next;
// 			}
// 		}
// 		else if (p2)
// 		{
// 			while (p2)
// 			{
// 				result->val = p2->val + result->val;
// 				ListNode* next = new ListNode();
// 				if (result->val >= 10)
// 				{
// 					next->val = result->val / 10;
// 					result->val %= 10;
// 				}
// 				result->next = next;
// 				pre = result;
// 				result = next;
// 				p2 = p2->next;
// 			}
// 		}
		ListNode* node = nullptr;
		if (p1)
			node = p1;
		else if (p2)
			node = p2;
		while (node)
		{
			result->val = node->val + result->val;
			ListNode* next = new ListNode();
			if (result->val >= 10)
			{
				next->val = result->val / 10;
				result->val %= 10;
			}
			result->next = next;
			pre = result;
			result = next;
			node = node->next;
		}

		if(result->val == 0)
		{
			pre->next = nullptr;
			delete result;
		}
		return head;
	}
};

int main()
{
	Solution s;
	ListNode a(3,nullptr);
	ListNode b(4, &a);
	ListNode c(2, &b);
	
	ListNode x(4, nullptr);
	ListNode y(6, &x);
	ListNode z(5, &y);

	s.addTwoNumbers(&c, &z);
}