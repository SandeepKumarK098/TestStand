# Clone only the required folder from Azure DevOps

$RepoUrl   = "https://ni.visualstudio.com/Users/_git/TestStand_migration"
$ClonePath = "C:\Users\admin\Desktop\TestStand_migration"

git clone --filter=blob:none --no-checkout $RepoUrl $ClonePath

Set-Location $ClonePath

git sparse-checkout init --cone
git sparse-checkout set "AutoTests/TS Auto/FeatureCategory/DotNet"

git checkout