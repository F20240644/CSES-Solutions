#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long

void foo(std::vector<ll> &v, ll i, ll &ans, ll l, ll r)
{
    ll n = v.size();
    if (i == n)
    {
        ans = std::min(ans, llabs(l - r));
        return;
    }
    foo(v, i + 1, ans, l + v[i], r);
    foo(v, i + 1, ans, l, r + v[i]);
}

int main()
{
    ll n;
    std::cin >> n;
    std::vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        std::cin >> v[i];
    ll ans = LLONG_MAX;
    foo(v, 0, ans, 0, 0);
    std::cout << ans << "\n";
    return 0;
}
