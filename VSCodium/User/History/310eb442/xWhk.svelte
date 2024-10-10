<script>
	import Social from '../atoms/Social.svelte';
	import { user } from '../../util/discord';

	import { GitHubIcon } from '@indaco/svelte-iconoir/github';
	import { DiscordIcon } from '@indaco/svelte-iconoir/discord';
	import { MailIcon } from '@indaco/svelte-iconoir/mail';
	import { CoffeeCupIcon } from '@indaco/svelte-iconoir/coffee-cup';
</script>

<div class="socials-container">
	<Social tip="pnnv" link="https://github.com/pnnv">
		<GitHubIcon color="var(--accent)" />
	</Social>

	<Social tip=pranav2 link={`https://discord.com/users/pranav2`}>
		<DiscordIcon color="var(--accent)" />
	</Social>

	<Social tip="prahlad.exe@gmail.com" link="mailto:prahlad.exe@gmail.com">
		<MailIcon color="var(--accent)" />
	</Social>
</div>

<style>
	.socials-container {
		display: flex;
		gap: 0.75rem;
	}
</style>
